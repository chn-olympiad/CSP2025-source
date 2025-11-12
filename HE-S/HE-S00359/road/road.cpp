#include<bits/stdc++.h>
using namespace std;
namespace code{
#define F(i,x,y) for(int i=x,__=y;i<=__;i++)
#define R(i,y,x) for(int i=y,__=x;i>=__;i--)
#define debug(x) cerr<<#x<<"="<<(x)<<endl
	using ll=long long;
	using uint=unsigned int;
	using ull=unsigned long long;
	const int N=10005,K=11,M=1200005;
	struct way{
		int v,w;
		constexpr way(const int& a=0,const int& b=0):v(a),w(b){};
	};
	bool operator<(const way& x,const way& y){
		return x.w>y.w;
	}
	vector<way>ways[N+K];
	int w[K];
	vector<way>op[K];

	struct tow{
		int u,v,w;
		constexpr tow(int a=0,int b=0,int c=0):u(a),v(b),w(c){}
	};

	tow tmp[M];
	void sort(tow a[],int n){
		int count[256];
		for(int i=0;i<=24;i+=8){
			memset(count,0,sizeof(count));
			F(j,1,n)count[(a[j].w>>i)&255]++;
			F(j,1,255)count[j]+=count[j-1];
			R(j,n,1)tmp[count[(a[j].w>>i)&255]--]=a[j];
			F(j,1,n)a[j]=tmp[j];
		}
	}

	int fa[N+K],rank[N+K];

	int find(int x){
		return fa[x]==x?(x):(fa[x]=find(fa[x]));
	}
	void link(int x,int y){
		x=find(x);y=find(y);
		if(rank[x]<rank[y]){
			fa[x]=y;
		}
		else {
			fa[y]=x;
			rank[x]+=(rank[x]==rank[y]);
		}
	}

	tow tmp1[M];
	ll rans(const int& n,int m,int com,const int& k){
		ll ans=0;
		F(i,1,n+k)fa[i]=i,rank[i]=0;
		F(i,1,k){
			if((1<<(i-1))&com){
				for(auto j:op[i]){
					ways[n+i].push_back(j);
				}
				ans+=w[i];
			}
		}
		int p=m;
		F(i,n+1,n+k){
			for(auto j:ways[i]){
				tmp1[++p]=tow(j.v,i,j.w);
			}
		}
		sort(tmp1+m,p-m);
		int p1=1,p2=m+1;
		while(p1<=m||p2<=p){
			int i;
			if(p1==m+1||(p2<=p&&tmp1[p2].w<tmp1[p1].w)){
				i=p2++;
			}
			else i=p1++;
			int u=tmp1[i].u,v=tmp1[i].v;
			if(find(u)==find(v))continue;
			ans+=tmp1[i].w;
			link(u,v);
		}
		F(i,1,k){
			if((1<<(i-1))&com){
				ways[n+i].clear();
			}
		}
		return ans;
	}

	int main(){
		freopen("road.in","r",stdin);
		freopen("road.out","w",stdout);
		cin.tie(0)->sync_with_stdio(0);
		int n,m,k;
		cin>>n>>m>>k;
		F(i,1,m){
			int u,v,w;
			cin>>u>>v>>w;
			ways[u].emplace_back(v,w);
			tmp1[i]=tow(u,v,w);
		}
		sort(tmp1,m);
		F(i,1,k){
			cin>>w[i];
			F(j,1,n){
				int opt;cin>>opt;
				op[i].emplace_back(j,opt);
			}
		}
		ll ans=0x7fffffffffffffffll;
		F(com,0,(1<<k)-1){
			ans=min(ans,rans(n,m,com,k));
		}
		cout<<ans;
		return 0;
	}
}
int main(){
	code::main();
	return 0;
}