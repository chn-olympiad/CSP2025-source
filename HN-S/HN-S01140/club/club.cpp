#include <bits/stdc++.h>
using namespace std;
int t,n,d[10010][3],x1,x2,x3,sum;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		sum=0;
		x1=0;
		x2=0;
		x3=0;
		for(int i=0; i<10010; i++) {
			for(int j=0; j<3; j++) {
				d[i][j]=0;
			}
		}
		cin>>n;
		for(int i=0; i<n; i++) {
			for(int j=0; j<3; j++) {
				cin>>d[i][j];
			}
		}
		int maxx=-1,maxj=0,maxi=0;
		while(x1+x2+x3<n) {
			maxx=-1;
			maxj=0;
			if(x1>=n/2) {
				for(int i=0; i<n; i++) {
					d[i][0]=-1;
				}
			}
			if(x2>=n/2) {
				for(int i=0; i<n; i++) {
					d[i][1]=-1;
				}
			}
			if(x3>=n/2) {
				for(int i=0; i<n; i++) {
					d[i][2]=-1;
				}
			}

			for(int i=0; i<=n; i++) {
				for(int j=0; j<3; j++) {
					if(maxx<=d[i][j]) {
						maxx=d[i][j];
						maxj=j;
						maxi=i;
					}
				}
			}
			int flag=1;
			for(int i=0; i<=n; i++) {
				for(int j=0; j<3; j++) {
					if(i!=maxi&&j!=maxj&&d[i][j]!=0) {
						flag=0;
					}
				}
			}
			if(flag) {
				d[maxi][maxj]=-1;
				maxx=0;
				for(int i=0; i<=n; i++) {
					for(int j=0; j<3; j++) {
						if(maxx<=d[i][j]) {
							maxx=d[i][j];
							maxj=j;
							maxi=i;
						}
					}
				}
			}
			d[maxi][0]=-1;
			d[maxi][1]=-1;
			d[maxi][2]=-1;
			sum+=maxx;
			if(maxj==0) {
				x1++;
			}
			if(maxj==1) {
				x2++;
			}
			if(maxj==2) {
				x3++;
			}
		}
		cout<<sum<<endl;





	}
	return 0;
}
