#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ulp(i,a,b) for(long long i=a;i<=b;i++)
#define dlp(i,b,a) for(long long i=b;i>=a;i--)
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define pb push_back
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!('0'<=c&&c<='9')){
		if(c=='-')f=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}
inline void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9)write(x/10);
	putchar(x%10+48);
}
struct Edge{
	int v,w;
};
struct E{
	int u,v,w;
};
bool cmp1(E x,E y){
	return x.w<y.w;
}
const int MAXN=10005;
int n,m,q,dt[MAXN],a[MAXN],sum;
vector<Edge> e[MAXN];
bool tl[MAXN];
vector<E> line;
int dfs(int u,int fa,int sp){
	int ans=0;//
//	puts("***");
//	write(u);
	ulp(i,0,e[u].size()-1){
		if(u==fa)break;
		int v=e[u][i].v,w=e[u][i].w;
		
		if(v==fa){
//			cout<<"///"<<w<<" " <<a[u]<<" " <<a[sp]<<"***\n";
			if(w>a[u]){
				ans+=w-a[u];
			}
//			cout<<ans<<"^^\n";
			break;
		}
	}
	ulp(i,0,e[u].size()-1){
		if(e[u][i].v==fa)continue;
		ans+=dfs(e[u][i].v,u,sp);
	}
	return ans;
}
void dfs1(int u,int fa,int sp){
	ulp(i,0,e[u].size()-1){
//		if(u==fa)break;
		int v=e[u][i].v,w=e[u][i].w;
		if(v==fa){
			if(w>a[u]){
//				ans+=w-a[u]-a[v];
				e[u][i].w=a[u];
				ulp(j,0,e[fa].size()-1){
					int v1=e[fa][j].v;
					if(v1==u){
						e[fa].erase(e[fa].begin()+j);
						break;
					}
				}
				e[sp].push_back({u,a[u]});
			}
			break;
		}
	}
	ulp(i,0,e[u].size()-1){
		if(e[u][i].v==fa)continue;
		dfs1(e[u][i].v,u,sp);
//		puts("**");
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),q=read();
	ulp(i,1,m){
		int u=read(),v=read(),w=read();
		line.pb((E){u,v,w});
	}
	sort(line.begin(),line.end(),cmp1);
	for(auto bbd:line){
		int u=bbd.u,v=bbd.v,w=bbd.w;
		if(tl[u]&&tl[v])continue;
		e[u].pb((Edge){v,w}),e[v].pb((Edge){u,w});
		sum+=w;
		tl[u]=tl[v]=true;
	}
	ulp(bbd,1,q){
		int cnt=-1*read(),fa=0,minn=1e9+5;
		ulp(i,1,n){
			a[i]=read();
			if(minn>a[i]){
				minn=a[i],fa=i;
			}
		}
		cnt-=minn;
//		cout<<cnt<<" ";
		cnt+=dfs(fa,-1,fa);
//		write(cnt);
		if(cnt>0){
			dfs1(fa,-1,fa);
			sum-=cnt;
		}
	}
	write(sum);
}
