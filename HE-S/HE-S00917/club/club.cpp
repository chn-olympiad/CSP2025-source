#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,sum=0;
	cin>>t;
	int n;
	cin>>n;
	int a[n][3];
	for(int i=1; i<=3; i++) {
		for(int j=1; j<=n; j++) {
			cin>>a[i][j];
		}
	}
	for(int j=1; j<=3; j++) {
		if(a[1][j]>a[2][j]&&a[1][j]>a[3][j]) {
			sum=sum+a[1][j];
		} else if(a[2][j]>a[1][j]&&a[2][j]>a[3][j]) {
			sum=sum+a[2][j];
		} else {
			sum=sum+a[3][j];
		}
	}
	cout<<sum<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}


