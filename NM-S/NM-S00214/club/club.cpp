#include<bits/stdc++.h>
using namespace std;
int f[20020][20020];
int m2[20021];
int a[20201];
int m[20010];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int j,i,n,mj,mi,cnt=0,d;
	cin>>n;
	for(i=1; i<=n; i++) {
		for(j=1; j<=3; j++) {
			cin>>f[i][j];
		}
	}
	while(a[mj]<=n/2) {

		for(i=1; i<=n; i++) {
			d=0;
			for(j=2; j<=3; j++) {
				m[i]=f[i][j-1];
				if(f[i][j]>f[i][j-1]) {
					m[i]=f[i][j];
					mj=j;
					d++;
				}
			}
			if(d==0) {
				m2[i]=max(f[i][mj+2],f[i][mj+1]);
			} else if(d==1) {
				m2[i]=max(f[i][mj-1],f[i][mj+1]);
			} else {
				m2[i]=max(f[i][mj-2],f[i][mj-1]);
			}
			if(a[mj]<=n/2) {
				a[mj]++;
				m[i]=f[i][mj];
			} else {
				m[i]=m2[i];
			}
		}
		for(i=1; i<=n; i++) {
			cnt+=m[i];
		}
		cout<<cnt;
		return 0;
	}
}
