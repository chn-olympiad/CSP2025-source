#include<bits/stdc++.h>
using namespace std;
int main() {
	int n,ii;
	cin>>ii;
	int c[ii];
	int d[ii];

	for(int k=0; k<ii ; k++) {
		cin>>n;
		int a[n][5],b[ii][n];
		int a1=0,a2=0,a3=0;
		int sum=0;
		for(int i=0; i<n; i++) {
			a[i][3]=0,a[i][4]=0;
			for(int j=0; j<3; j++) {
				cin>>a[i][j];
				if(a[i][j]>a[i][3]) {
					a[i][4]=a[i][3];
					a[i][3]=a[i][j];
					b[k][i]=j;

				}
			}
			sum=sum+a[i][3];
			if(b[k][i]==0) {
				a1++;
			}
			if(b[k][i]==1) {
				a2++;
			}
			if(b[k][i]==2) {
				a3++;
			}

			if(a1>n/2||a2>n/2||a3>n/2) {
				
			}
			c[k]=sum;
		}
	}

	for(int t=0; t<ii; t++) {
		cout<<c[t]<<endl;
	}
	return 0;
}
