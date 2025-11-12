#include<bits/stdc++.h>
#define int long long
using namespace std;

struct node{
	int u,v,w;
}e[1100010];


int n,m,k,ans=LONG_LONG_MAX;
int rht[12];
int fa[10010];


int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}

bool cmp(node x,node y){
	return x.w<y.w;
}

signed main( ){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		e[i]={a,b,c};
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			if(j==0) scanf("%lld",&rht[i]);
			else{
				int ll;scanf("%lld",&ll);
				e[++m]={i+n,j,ll};
			}
		}
	}
	
	sort(e+1,e+1+m,cmp);
	for(int j=0;j<(1<<k);j++){
		for(int i=1;i<=n+k;i++){
			fa[i]=i;
		}
		int sum=0;
		for(int i=0;i<k;i++){
			if(((1<<i)&j)) sum+=rht[i+1];
		}
		for(int i=1;i<=m;i++){
			int u=e[i].u,v=e[i].v,w=e[i].w;
			if(u>n&&(!((1<<(u-n-1))&j))) continue; 
			if(find(u)==find(v)) continue;
			fa[find(u)]=find(v);
	//		cout<<u<<" "<<v<<" "<<w<<endl;
			sum+=w;
			if(sum>=ans) break;
		}
	//	cout<<endl<<sum<<endl;
		ans=min(sum,ans);
	}
	cout<<ans;
	return 0;
}
/*
4 4 2 
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
