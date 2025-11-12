#include<bits/stdc++.h>
using namespace std;
long long n,m,kk[15][1000010],a[1005][1005],f,ans[10001];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m>>f;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		a[x][y]=z;
		a[y][x]=z;
	}
	for(int i=1;i<=f;i++){
		for(int j=0;j<=n;j++){
			cin>>kk[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		ans[i]=10000001;
	} 
	ans[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			for(int k=n;k>=1;k--){
			if(a[j][k]!=0)
				ans[i]=min(ans[i-1]+a[j][k],ans[i]);
				for(int w=1;w<=f;w++){
					ans[i]=min(ans[i-1]+kk[w][j]+kk[w][k]+kk[w][0],ans[i]);
				}
			}
		}
	}
	cout<<ans[n];
	return 0;
}

