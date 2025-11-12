#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define For(a,b,c) for(int a=b;a<=c;a++)
#define Fro(a,b,c) for(int a=b;a>=c;a--)
#define int long long
#ifdef __linux
#define gc getchar_unlocked
#else
#define gc _getchar_nolock
#endif
using namespace std;
using namespace __gnu_pbds;
const int N=1e4+5;
int read(){
	char ch=gc();
	int i=0;
	while((ch^32)&&(ch^10)){
		i=(i<<3)+(i<<1)+(ch-'0');
		ch=gc();
	} 
	return i;
}
struct edge{
	int u,v,w;
	bool operator<(const edge&b)const{return w<b.w;}
};
vector<edge> p;
vector<edge> g;
int fa[N],n,m,k,c[N],e[N][N],ans;
int Fa(int x){
	if(fa[x]==x) return x;
	return fa[x]=Fa(fa[x]);
}
void merge(int x,int y){
	fa[Fa(x)]=Fa(y);
}
int kruscal(){
	int sum=0,cnt=0;
	sort(g.begin(),g.end());
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(edge i:g){
		int u=i.u,v=i.v,w=i.w;
		if(Fa(u)==Fa(v)) continue;
		merge(u,v);
		sum+=w,cnt++;
		if(cnt==n-1) break;
	}
	return sum;
}
void dfs(int d,int ch){
	if(d==k){
		g=p;
		int cnt=1,res=0;
		while(ch){
			int now=ch&1;
			if(now){
				For(i,1,n){
					For(j,i+1,n){
						g.push_back({i,j,e[cnt][j]+e[cnt][i]});
						g.push_back({j,i,e[cnt][i]+e[cnt][j]});
					}
				}
				res+=c[cnt];
			}
			cnt++;
			ch>>=1;
		}
		ans=min(ans,kruscal()+res);
		return;
	}
	dfs(d+1,ch<<1);
	dfs(d+1,ch<<1|1);
}//O(2^k*(mlogm+n^2))£¬6e8*´ó³£Êý 
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	For(i,1,m){
		int u,v,w;
		u=read(),v=read(),w=read();
		g.push_back({u,v,w});
		g.push_back({v,u,w});
	}
	ans=kruscal();
	p=g;
	if(k==0)
		return cout<<ans,0;
	bool f1=1;
	For(i,1,k){
		c[i]=read();
		if(c[i]) f1=0;
		For(j,1,n){
			e[i][j]=read();
		}
	}
	if(f1){
		For(i,1,n){
			For(j,i+1,n){
				For(kk,1,k)
					g.push_back({i,j,e[kk][j]+e[kk][i]}),
					g.push_back({j,i,e[kk][i]+e[kk][j]});
			}
		}
		ans=min(ans,kruscal());
		cout<<ans;
		return 0;
	}
	dfs(0,0);
	cout<<ans;
	return 0;
}
