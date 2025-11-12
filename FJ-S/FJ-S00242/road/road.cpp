#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define int long long
struct node{int u,v,w,id;};
bool operator<(node a,node b){return a.w>b.w;}
int n,m,k,ans,c[15],a[15][10005],f[10015],u,v,w,cnt;
bool pd[15];
vector<pair<int,int>> e[10015];
int find(int x){return f[x]==x?x:find(f[x]);}
priority_queue<node> q;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i = 1;i<=n;i++) f[i]=i;
	for(int i = 1;i<=m;i++) cin>>u>>v>>w,q.push({u,v,w,0});
	for(int i = 1;i<=k;i++){
		cin>>c[i];
		for(int j = 1;j<=n;j++) cin>>a[i][j];
		for(int j = 1;j<=n;j++)
			for(int kk = j+1;kk<=n;kk++)
				q.push({j,kk,a[i][j]+a[i][kk]+c[i],i});
	}
	cnt=n-1;
	while(cnt){
		node tmp=q.top();
		q.pop();
		if(find(tmp.u)!=find(tmp.v)){
			if(tmp.id&&c[tmp.id])
				for(int i = 1;i<=n;i++)
					for(int j = i+1;j<=n;j++)
						if(find(i)!=find(j))
							q.push({i,j,a[tmp.id][i]+a[tmp.id][j],0});
			f[find(tmp.u)]=find(tmp.v);
			ans+=tmp.w;
			cnt--;
		}
	}
	cout<<ans;
	return 0;
}
/*
2 1 1 
1 2 5
3 1 4
*/
