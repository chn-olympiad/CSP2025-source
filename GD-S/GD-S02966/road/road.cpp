#include<bits/stdc++.h>
using namespace std;
long long n,m,k,a[1000005][5],c[15][10005],f[1005][1005],ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
		}
		f[a[i][1]][a[i][2]]=a[i][3];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i][0];
		for(int j=1;j<=n;j++){
			cin>>c[i][j];
		}
		for(int j=1;j<=m;j++){
			f[a[j][1]][a[j][2]]=min(f[a[j][1]][a[j][2]],c[i][a[j][1]]+c[i][0]+c[i][a[j][2]]);
		}
	}
	for(int i=1;i<=m;i++){
		ans+=f[a[i][1]][a[i][2]];
	}
	cout<<ans;
	return 0;
}
