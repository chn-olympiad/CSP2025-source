#include <bits/stdc++.h>
using namespace std;
int a[105];
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,js=1,r;	//行数，列数 
	cin>>n>>m;
	for (int i=1;i<=n*m;i++) {
		cin>>a[i];
	}	
	for (int i=1;i<=n*m;i++) {
		if (i==1) {
			r=a[i];
		} else {
			if (a[i]>r) {
				js++;
			}
		}
	}
	for (int i=1;i<=m;i++) {
		if (i%2==1) {
			for (int j=1;j<=n;j++) {
				js--;
				if (js==0) {
					cout<<i<<' '<<j;
					return 0;
				}
			}
		} else {
			for (int j=n;i>=0;j--) {
				js--;
				if (js==0) {
					cout<<i<<' '<<j;
					return 0;
				}
				if (j==1) {
					break;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
