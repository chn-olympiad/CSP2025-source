#include <bits/stdc++.h>
using namespace std;
char nd[520];
int nx[520];
int nxer[249520][520];
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n;
	cin >> n;
	int m;
	cin >> m;
	for(int i=1; i<=n; i++) {
		cin >> nd[i];
	}
	for(int i=1; i<=n; i++) {
		cin >> nx[i];
	}
	int pxcs=n*n-n;
	int zj=1;
	int zjt=2;
	for(int i=1; i<=pxcs; i++) {
		int bo;
		bo=nx[zj];
		nx[zj]=nx[zjt];
		nx[zjt]=bo;
		for(int j=1; j<=n; j++) {
			nxer[i][j]=nx[j];
		}
		zj++;
		zjt++;
		if(zj==n) {
			zj=1;
			zjt=2;
		}
	}
	int count=0;
	int ycount=0;
	int ncount=0;
	for(int i=1; i<=pxcs; i++) {
		ycount=0;
		ncount=0;
		for(int j=1; j<=n; j++) {
			if(nd[j]=='1'&&ncount<nxer[i][j]){
				ycount++;
			}else{
				ncount++;
			}
		}
		if(ycount>=m){
			count++;
		}
	}
	cout << count%998244353;
	return 0;
}
