#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,ans;
int q[100005];
int b[15][1000005];
int cnt[15];
struct o{
	int x,y,z;
	int f;
}g[2000005];
int a[5005][5005];
int find(int x){
	if(q[x]!=x)q[x]=find(q[x]);
	return q[x];
}
bool cmp(o x,o y){
	return x.z<y.z;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(a,0x3f,sizeof a);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		a[x][y]=a[y][x]=min(a[x][y],z);
	}
	for(int i=1;i<=k;i++){
		cin>>b[i][0];
		for(int j=1;j<=n;j++)cin>>b[i][j];
	}
	m=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int f=0;
			for(int l=1;l<=k;l++)if(b[l][i]+b[l][j]+b[l][0]<a[i][j])a[i][j]=b[l][i]+b[l][j]+b[l][0],f=l;
			g[++m]={i,j,a[i][j],f};
		}
	}
	for(int i=1;i<=n;i++)q[i]=i;
	sort(g+1,g+m+1,cmp);
	for(int i=1,c=1;c<n;i++){
		int x=g[i].x,y=g[i].y;
		if(find(x)!=find(y)){
			q[find(x)]=find(y);
			c++;
			ans+=g[i].z;
			cnt[g[i].f]++;
		}
	}
	for(int i=1;i<=k;i++)if(cnt[i])ans-=(cnt[i]-1)*b[i][0];
	cout<<ans;
	return 0;
}/*
22:14
23:15
5 5 3
1 2 3
2 3 4
4 5 2
1 5 2
2 4 1
1 2 3 1 1 2
3 1 1 1 1 1
100 0 0 0 0 0

*/
