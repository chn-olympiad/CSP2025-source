#include<bits/stdc++.h>
using namespace std;
struct stdc {
	int b1,b2,b3,yx;
	bool xg;
} a[500010];
int t,n,myd;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0; i<t; i++) {
		cin>>n;
		if(n==2) {
			for(int j=0; j<2; j++) {
				cin>>a[j].b1>>a[j].b2>>a[j].b3;
			}
			myd+=max(a[0].b1+a[1].b2,max(a[0].b1+a[1].b3,max(a[0].b2+a[1].b1,max(a[0].b2+a[1].b3,max(a[0].b3+a[1].b1,a[0].b3+a[1].b2)))));
			cout<<myd<<endl;
			myd=0;
			for(int j=0; j<n; j++) {
				a[j].xg=false;
			}
		} else {
			for(int j=0; j<n; j++) {
				cin>>a[j].b1>>a[j].b2>>a[j].b3;
				if(max(a[j].b1,max(a[j].b2,a[j].b3))==a[j].b1)a[j].yx=1;
				else if(max(a[j].b1,max(a[j].b2,a[j].b3))==a[j].b2)a[j].yx=2;
				else a[j].yx=3;
			}
			int m=n,m1=0,m2=0,m3=0;
			while (m>0) {
				int max1=0,max2=0,max3=0,wz1=0,wz2=0,wz3=0;
				for(int j=0; j<n; j++) {
					if(a[j].yx==1&&max1<a[j].b1&&a[j].xg==false) {
						max1=a[j].b1;
						wz1=j;
					} else if(a[j].yx==2&&max2<a[j].b2&&a[j].xg==false) {
						max2=a[j].b2;
						wz2=j;
					} else {
						if(max3<a[j].b3&&a[j].xg==false) {
							max3=a[j].b3;
							wz3=j;
						}
					}
				}
				a[wz1].xg=true;
				a[wz2].xg=true;
				a[wz3].xg=true;
				if(max1!=0&&m1<n/2&&m>0) {
					myd+=max1;
					m1++;
				}
				if(max2!=0&&m2<n/2&&m>0) {
					myd+=max2;
					m2++;
				}
				if(max3!=0&&m3<n/2&&m>0) {
					myd+=max3;
					m3++;
				}
				m--;
			}
			cout<<myd<<endl;
			myd=0;
			for(int j=0; j<n; j++) {
				a[j].xg=false;
			}
		}

	}
	return 0;
}
