#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[100005],b[100005],c[100005];
int f[505][505][505];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	cin>>t;
	while (t>0) {
		t--;
		memset(f,0,sizeof(f));
		cin>>n;
		for (int i=1;i<=n;i++) {
			cin>>a[i]>>b[i]>>c[i];
		}
		for (int k=1;k<=n;k++) {
			for (int i=n/2;i>=1;i--) {
				for (int j=n/2;j>=1;j--) {
					f[k][i][j]=max(f[k-1][i-1][j]+a[k],f[k][i][j]);
					f[k][i][j]=max(f[k-1][i][j-1]+b[k],f[k][i][j]);
					f[k][i][j]=max(f[k-1][i][j]+c[k],f[k][i][j]);
				}
			}
		}
		cout<<f[n][n/2][n/2]<<endl;
	}
	return 0;
}
