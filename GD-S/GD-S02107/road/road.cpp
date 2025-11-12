#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F(i,a,b) for(int i=(a);i<=(b);i++)
const int N=1e4+20,inf=1e18;
int n,m,k,a[N][15],c[15],f[N],ans=inf;
struct edge{
	int u,v,w;
};
int find(int u){return f[u]==u?f[u]:f[u]=find(f[u]);}
bool cmp(const edge&x,const edge&y){return x.w<y.w;}
bool checkA(){
	F(i,1,k)if(c[i]!=0)return 0;
	return 1;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	vector<edge>g(m);
	for(edge&x:g)cin>>x.u>>x.v>>x.w;
	F(i,1,k){
		cin>>c[i];
		F(j,1,n)cin>>a[j][i];
	}
	if(checkA()){
		int ans=0,cc=n+k;
		F(i,1,k)F(j,1,n)g.push_back({n+i+1,j,a[j][i]});
		sort(begin(g),end(g),cmp);
		iota(f+1,f+n+k+1,1);
		for(const edge&x:g){
			int a=find(x.u),b=find(x.v);
			if(a!=b)f[a]=b,ans+=x.w,cc--;
		}
		cout<<ans<<"\n";
		return 0;
	}
	if(m<=1e5){
		for(int mk=0;mk<(1<<k);mk++){//确认第j个点变不变 
			int sum=0;
			vector<edge>G(g);
			for(int i=0;i<k;i++)if((mk&(1<<i))>>i==1){
				sum+=c[i+1];
				F(j,1,n)G.push_back({n+i+1,j,a[j][i+1]});
			}
			sort(begin(G),end(G),cmp);
			iota(f+1,f+n+k+1,1);
			for(const edge&x:G){
				int a=find(x.u),b=find(x.v);
				if(a!=b)f[a]=b,sum+=x.w;
			}
			ans=min(ans,sum);
		}
		cout<<ans<<"\n";
		return 0;
	}else{
		F(i,1,k){
			int sum=c[i];
			vector<edge>G(g);
			F(j,1,n)G.push_back({n+i+1,j,a[j][i]});
			sort(begin(G),end(G),cmp);
			iota(f+1,f+n+10,1);
			for(const edge&x:G){
				int a=find(x.u),b=find(x.v);
				if(a!=b)f[a]=b,sum+=x.w;
			}
			ans=min(ans,sum);
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}
/*
at least 48pts
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

会T，子集枚举还是太劣了 
考虑怎么优化,去掉子集枚举 

*/
