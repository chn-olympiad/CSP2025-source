#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=3e5+5;
ll T,n,x,cnt,ans;
struct node{
	ll x,id1,id2;
}b[N];
bool cmp(node l,node r){
	return l.x>r.x; 
}
struct Node{
	ll x,id;
}a[N][4],c[N][4];
bool cmp1(Node l,Node r){return l.x>r.x;}
ll sum[N],id;
ll vis[N][4];
priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > > q[5];
ll xx,idd;
ll f[1005][1005],g[1005][1005];
bool remove(ll w,ll i,ll j){
	if(vis[i][j]) return 0;
	if((ll)(q[j].size()+1)<=(ll)(n/2)){
		q[j].push({w,i});vis[i][j]=1;
		sum[i]++;
		return 1;
	}
	else{
		ll xx=q[j].top().first,idd=q[j].top().second;
		if(w+a[idd][sum[idd]+1].x>xx&&sum[idd]+1<=3){
			if(remove(a[idd][sum[idd]+1].x,idd,a[idd][sum[idd]+1].id)){
				q[j].pop();
				q[j].push({w,i});
				vis[i][j]=1;
				sum[i]++;
				return 1;
			}
		}
	}
	return 0;
}
void solve(){
	scanf("%lld",&n),ans=cnt=0;
	for(int i=1;i<=n;i++) vis[i][1]=vis[i][2]=vis[i][3]=0,sum[i]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			while(!q[j].empty()) q[j].pop();
			scanf("%lld",&a[i][j].x);
			a[i][j].id=j,c[i][j]=a[i][j];
			b[++cnt].x=a[i][j].x,b[cnt].id1=i,b[cnt].id2=j;
		}
		sort(a[i]+1,a[i]+4,cmp1);
	}
	if(n<=200){
		memset(f,0,sizeof f);
		for(int i=1;i<=n;i++){
			for(int j=0;j<=min(n/2,(ll)i);j++){
				for(int k=0;k<=min(n/2,(ll)i);k++){
					if((i-j-k)<=n/2&&(i-j-k)) g[j][k]=max(g[j][k],f[j][k]+c[i][3].x);
					if(j) g[j][k]=max(g[j][k],f[j-1][k]+c[i][1].x);
					if(k) g[j][k]=max(g[j][k],f[j][k-1]+c[i][2].x);
					ans=max(ans,g[j][k]);
				}
			}
			for(int j=0;j<=n/2;j++) for(int k=0;k<=n/2;k++) f[j][k]=g[j][k],g[j][k]=0;
		}		
	}
	else{
		sort(b+1,b+cnt+1,cmp);
		for(int i=1;i<=cnt;i++){
			if(vis[b[i].id1][1]||vis[b[i].id1][2]||vis[b[i].id1][3]) continue;
			remove(b[i].x,b[i].id1,b[i].id2);
		}
		for(int i=1;i<=3;i++){
			while(!q[i].empty()){
				ans+=q[i].top().first;
				q[i].pop(); 
			}
		}		
	}
	printf("%lld\n",ans);
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--) solve();
	return 0;
}
/*
1
10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926



*/
