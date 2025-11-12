#include<bits/stdc++.h>//24~32
using namespace std;
#define int long long
#define a3 array<int,3>
const int N=1e4+10,M=1e6+10;
int n,m,k,cnt,ans;
array<int,3> e[M];
priority_queue<a3,vector<a3>,greater<a3> > q;
int fa[N];
void init(){for(int i=1;i<=n;i++) fa[i]=i;}
int find(int x){
	if(fa[x]!=x) fa[x]=find(fa[x]);
	return fa[x];
}
int c[20];
int a[20][N];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	init();
	for(int i=1;i<=m;i++) cin>>e[i][0]>>e[i][1]>>e[i][2],q.push({e[i][2],e[i][0],e[i][1]});
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	for(int w=1;w<=k;w++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				q.push({a[w][i]+a[w][j],i,j});
	while(!q.empty()&&cnt<=n-1){
		int u=q.top()[1];
		int v=q.top()[2];
		int len=q.top()[0];
		q.pop();
		int fx=find(u),fy=find(v);
		if(fx==fy) continue;
		fa[fx]=fy;
		ans+=len,cnt++;
		cout<<u<<" "<<v<<" "<<len<<"\n";
	}
	cout<<ans<<"\n";
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
0 1 8 2 4
0 1 3 2 4
*/
