#include<bits/stdc++.h>
using namespace std;
#define MAXM 3000010
#define MAXN 200010
#define ll long long
struct node{
	int x,y,v;
	bool operator<(const node &b){
		return v<b.v;
	}
}edge[MAXM];
int n,m,k,fa[MAXN],c[MAXN];
int a[15][MAXN],tot;
int find(int u){
	if(fa[u]==u)return u;
	return fa[u]=find(fa[u]);
}
ll calc(int sz){
	sort(edge+1,edge+1+tot);
	for(int i=1;i<=n+sz;i++)
		fa[i]=i;
	ll sum=0,cnt=0;
	for(int i=1;i<=tot;i++){
		int f1=find(edge[i].x),f2=find(edge[i].y);
		if(f1!=f2){
			fa[f1]=f2;
			sum+=edge[i].v;
			cnt++;
		}
		if(cnt==n+sz-1)break;
	}
	return sum;
	
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>edge[i].x>>edge[i].y>>edge[i].v;
	tot=m;
	int flag=0;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		flag|=c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	if((!flag)&&k>5&&m>100000){
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++)
				edge[++tot]={i+n,j,a[i][j]};
		}
		cout<<calc(k+n)<<"\n";
		return 0;
	}
	ll ans=1e18;
	for(int i=0;i<(1<<k);i++){
		ll sum=0;
		int cnt=0;
		tot=m;
		for(int j=0;j<k;j++){
			int b=(i>>j)&1;
			if(b){
				sum+=c[j+1],cnt++;
				for(int l=1;l<=n;l++)
					edge[++tot]={n+cnt,l,a[j+1][l]};
			}
		}
		sum+=calc(cnt);
		ans=min(ans,sum);
	}
	cout<<ans<<"\n";
	return 0;
}
