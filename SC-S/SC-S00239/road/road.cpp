#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define f(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i>=b;i--)
const int N=10000+6,M=2e6+6;
struct node{
	int u,v,w,val;
}x[M],y[N];
bool cmp(node l,node p){
	return l.w<p.w;
}
int c[N];
int dis[20][N];
int fa[N];
int find(int x){return (fa[x]==x)?x:fa[x]=find(fa[x]);}
signed main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("road.in","r",stdin);freopen("road.out","w",stdout);
	int n,m,k;cin>>n>>m>>k;
	int cnt=0;f(i,1,m){
		int a,b,c;cin>>a>>b>>c;x[++cnt].u=a,x[cnt].v=b,x[cnt].w=c;
	}sort(x+1,x+1+m,cmp);
	f(i,1,k){
		cin>>c[i];f(j,1,n)cin>>dis[i][j];
	}
  int maxn=1e18;
	f(i,0,(1<<k)-1){
		int ans=0;int num=cnt;int d=n;
		f(j,0,k-1){
			if((i>>j)&1){
				ans+=c[j+1];
				f(k,1,n){
					x[++num].u=++d,x[num].v=k,x[num].w=dis[j+1][k];
				}
			}
		}
		sort(x+1,x+1+num,cmp);
		f(i,1,n)fa[i]=i;int knt=0;
		f(i,1,num){
			int fx=find(x[i].u),fy=find(x[i].v);
			if(fx!=fy){
				ans+=x[i].w;fa[fx]=fy;knt++;
				if(knt==d-1){
					break;
				} 
			}
		}maxn=min(maxn,ans);
	}
	cout<<maxn;
} 