#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
namespace yyh{
	int n,m,k;
	struct edge{
		int a,b,w;
	}a[1000005],b[200005],c1[200005];
	int p[20005];
	int find(int x){
		if(p[x]==-1)return -1;
		if(p[x]==x)return x;
		return p[x]=find(p[x]);
	}
	bool cmp(edge x,edge y){
		return x.w<y.w;
	}
	int cnt;
	int maxn=0;
	int cnn[15],o[15];
	int kruskal(int p1,int n,int m){
		for(int i=1;i<=n;i++)
			p[i]=i;
		cnt=0;
		sort(a+1,a+m+1,cmp);
		int k=0,ans=0;
		for(int i=1;i<=m;i++){
			int fx=find(a[i].a);
			int fy=find(a[i].b);
			if(fx!=fy){
				p[fx]=fy;
				k++;
				maxn=max(maxn,a[i].w);
				b[++cnt]=a[i];
				int x=a[i].a,y=a[i].b,w=a[i].w;
				if(max(x,y)>p1&&min(x,y)<=p1)cnn[max(x,y)-p1]++,o[min(x,y)-p1]+=w;
				ans+=a[i].w;
				if(k==n-1)return ans;
			}
		}
		return 1e9;
	}
	int c[15],w[15][100005];
	bool v[15];
	int ooo[15],ans;
	void dfs(int cnt,int x){
		if(x>k){
			int cn=n-1;
			memcpy(a,c1,sizeof(c1));
			for(int i=1;i<=cnt;i++){
				cnn[i]=0;
				int t=ooo[i];
				for(int j=1;j<=n;j++){
					a[++cn].a=n+i;
					a[cn].b=j;
					a[cn].w=w[t][j];
				}
			}
			int l=kruskal(n,n+cnt,cn);
			for(int i=1;i<=cnt;i++){
				if(cnn[i]>=2)l+=c[ooo[i]];
				else l-=o[i];
			}
			ans=min(ans,l);
			return;
		}
		dfs(cnt,x+1);
		ooo[cnt+1]=x;
		dfs(cnt+1,x+1);
	}
	signed main(){
		cin>>n>>m>>k;
		if(n==0)return 0;
		for(int i=1;i<=m;i++){
			int u,v,w;
			cin>>u>>v>>w;
			a[i].a=u;
			a[i].b=v;
			a[i].w=w;
		}
		ans=kruskal(n,n,m);
		memcpy(a,b,sizeof(b));
		memcpy(c1,b,sizeof(b));
		for(int i=1;i<=k;i++){
			cin>>c[i];
			for(int j=1;j<=n;j++)
				cin>>w[i][j];
		}
		dfs(0,1);
		cout<<ans<<endl;
		return 0;
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	yyh::main();
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
