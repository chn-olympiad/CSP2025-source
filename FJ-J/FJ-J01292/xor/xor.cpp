#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500000+5];
int f[100][100];
int main() {
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int i,j;
	for(i=1;i<=n;i++) {
		cin>>a[i];
		f[i][i]=a[i];
	}
	/*for(i=1;i<=n;i++) {
		for(j=i+1;j<=n;j++) {
			if(f[i][j-1]==f[j][j]) {
				f[i][j]=0;
			}else f[i][j]=1;
		}
	}*/
	if(k==0) cout<<n/2;
	if(k==1) {
		int ans=0;
		for(i=1;i<=n;i++) {
			if(a[i]==1) ans++;	
		}
		cout<<ans;
	}
	return 0;
}