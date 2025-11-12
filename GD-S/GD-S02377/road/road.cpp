#include <bits/stdc++.h>
using namespace std;
int mp[10005][10005],c[15],a[10005];
long long sum,maxn=1e9;
int n,m,k;
int b[10005];
void dfs(int x){
	x++;
	if(x>n){
		for(int i=1;i<=n;i++)
		{
			sum+=a[i];
		}
		maxn=min(maxn,sum);
	}
	for(int i=1;i<=n;i++)
	{
		if(i==x) continue;
		if(mp[x][i]==0) continue;
		a[x]=mp[x][i];
		dfs(x);
		
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int x,y,z;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>z;
		mp[x][y]=z;
		mp[y][x]=z;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i]; //c为乡村改造价格 
		for(int j=1;j<=n;j++){
			cin>>a[j];//a为到第j城市的路费 
		}
		for(int j=1;j<n;j++){
			for(int l=1;l<=n;l++){
				mp[j][l]=min(mp[j][l],a[j]+a[l]+c[i]);
			}
		}
	}
	cout<<maxn;
	return 0;
}
