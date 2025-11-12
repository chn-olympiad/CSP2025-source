#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1; i<=t; i++) {
		int n,D=0;
		cin>>n;
		int a[n][3],c[3];
		c[1]=0;
		c[2]=0;
		c[3]=0;
		for(int j=1; j<=n; j++) {
			cin>>a[j][1]>>a[j][2]>>a[j][3];
		}
		for(int j=1; j<=n; j++) {
			if(a[j][1]>a[j][2]>a[j][3]||a[j][1]>a[j][3]>a[j][2]) {
				D+=a[j][1];
				c[1]++;
				if(a[j][2]>a[j][3]) {
					D+=a[j][2];
				}
				else {
					D+=a[j][3];
				}
			}
		
		if(a[j][2]>a[j][1]>a[j][3]||a[j][2]>a[j][3]>a[j][1]) {
				D+=a[j][2];
				c[2]++;
				if(c[2]>(n/2)) {
					c[2]--;
					D-=a[j][2];
					if(a[j][1]>a[j][3]) {
						D+=a[j][1];
					} else {
						D+=a[j][3];
					}
				}
				cout<<D;
			}
			if(a[j][3]>a[j][2]>a[j][1]||a[j][3]>a[j][1]>a[j][2]) {
				D+=a[j][3];
				c[3]++;
				if(c[3]>(n/2)) {
					c[3]--;
					D-=a[j][3];
					if(a[j][2]>a[j][1]) {
						D+=a[j][2];
					} else {
						D+=a[j][1];
					}
					cout<<D;
				}
			}
		}
		cout<<D<<"\n";
	}
	return 0;
}
