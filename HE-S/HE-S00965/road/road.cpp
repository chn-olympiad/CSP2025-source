#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>//AFO T.T
using namespace std;
int n,m,k,ans=-2e9;
vector<int>edge[1005],wi[1005];
int c[15],a[1005][1005];
int f[1005][1005];
void solve(){
	//cout<<"a";
	for(int kk=1;kk<=k;kk++)
		for(int i=1;i<=n;i++){
			for(int j=0;j<edge[i].size();j++){
				a[i][edge[i][j]]=min(a[i][edge[i][j]],wi[i][j]);
				}}
	//cout<<"a";
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n+k;i++)f[i][i]=0;
	for(int c=1;c<=n;c++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],a[i][c]+a[c][j]);
		}
	}
	//cout<<"a";
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)ans=max(ans,f[i][j]);
	}
	cout<<ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int cum=0;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		edge[u].push_back(v);
		edge[v].push_back(u);
		wi[u].push_back(w);
		wi[v].push_back(w);}
	for(int j=1;j<=k;j++){
		scanf("%d",&c[j]);
		if(c[j]==0)cum++;
		for(int i=1;i<=n;i++)scanf("%d",&a[j][i]);}
	if(cum==n)solve();
	else cout<<0;
	return 0;
}
