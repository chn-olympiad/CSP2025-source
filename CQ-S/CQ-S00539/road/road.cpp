#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const ll N=10005;
ll n,m,k,x,y;
ll c[N],a[15][N],f[N],ans,b[1005][1005];
struct node{
	ll x,y,z;
}w[1000005];
ll find(ll x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
bool cmp(node a,node b){
	return a.z<b.z;
}
ll solve(ll s){
	ll sum=0,t=0;
	node ww[1000005];
	for(int i=1;i<=m;i++) ww[i]=w[i];
	for(int i=1;i<=n;i++) f[i]=i;
	memset(b,0x3f,sizeof(b));
	for(int i=1;i<=m;i++){
		b[w[i].x][w[i].y]=min(b[w[i].x][w[i].y],w[i].z);
		b[w[i].y][w[i].x]=min(b[w[i].y][w[i].x],w[i].z);
	}
	for(int i=1;i<=k;i++){
		if(((s>>i-1)&1)==0) continue;
		sum+=c[i]; 
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(j==k) continue; 
				b[j][k]=min(b[j][k],a[i][j]+a[i][k]);
			}
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) if(b[i][j]!=0x3f3f3f3f3f3f3f3f) ww[++t]={i,j,b[i][j]};
	sort(ww+1,ww+t+1,cmp);
	for(int i=1;i<=t;i++){
		if(find(ww[i].x)==find(ww[i].y)) continue;
		sum+=ww[i].z;
		f[find(ww[i].x)]=find(ww[i].y);
	}	
	ans=min(ans,sum);
	//exit(0);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=1;i<=m;i++)
		cin>>w[i].x>>w[i].y>>w[i].z;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	if(k==0){
		sort(w+1,w+m+1,cmp);
		for(int i=1;i<=m;i++){
			if(find(w[i].x)==find(w[i].y)) continue;
			ans+=w[i].z;
			f[find(w[i].x)]=find(w[i].y);
		}
		cout<<ans<<endl;
	}
	else{
		ans=1e18;
		for(int i=0;i<(1<<k);i++){
			solve(i);
		}
		cout<<ans<<endl;
	}
	return 0;
}

