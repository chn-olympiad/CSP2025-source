#include <bits/stdc++.h>
using namespace std;
int n, m, z[15][15], a[109], b;
bool cmp(int a,int b)
{
	if (a>b) return true;
	else return false;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n*m;i++) {
		cin >> a[i];
		if (i == 1) {
			b = a[i];
		}
	}
	sort(a+1,a+n*m+1,cmp);
	for (int i=1;i<=m;i++) {
		if (i % 2 == 1) {
			for (int j=1;j<=n;j++) {
				z[j][i]=a[(i-1)*n+j];
				if (z[j][i] == b) {
					cout << i << " " << j;
				}
			}
		}
		else {
			for (int j=n;j>=1;j--) {
				z[j][i]=a[i*n-j+1];
				if (z[j][i] == b) {
					cout << i << " " << j;
				}
			}
		}	
	}
	return 0;
}
