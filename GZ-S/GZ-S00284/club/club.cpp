//GZ-S00284 贵阳市第一实验中学 槐延东 
#include <bits/stdc++.h>
using namespace std;
int n,sum1[10],sum2[10],sum3[10];

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;
	while(n--) {
		int t;
		cin>>t;
		for(int i=1; i<=t; ++i) {
			int a[10][10] = {0},num=0,tx1=0,tx2=0,tx3=0;
			for(int j=1; j<=3; ++i) {
				cin>>a[i][j];
			}
			if(a[i][1]>a[i][2] && a[i][1] > a[i][3]) {
				if(tx1 < (t/2)){
					sum1[i] = a[i][1];
					sort(sum1+1,sum1+t+1);
					tx1+=1;
				} else {
					if(a[i][1]>sum1[1]) {
						sum1[1] = 0;
						sum1[1] = a[i][1];
						sort(sum1+1,sum1+t+1);
					}
				}
			}
			if(a[i][2]>a[i][1] && a[i][2] > a[i][3]) {
				if(tx2<(t/2)){
					sum2[i] = a[i][2];
					sort(sum2+1,sum2+t+1);
					tx2+=1;
				} else {
					if(a[i][2]>sum2[1]) {
						sum2[1] = 0;
						sum2[1] = a[i][2];
						sort(sum2+1,sum2+t+1);
					}
				}
			}
			if(a[i][3]>a[i][1] && a[i][3] > a[i][2]) {
				if(tx3<(t/2)) {
					sum3[i] = a[i][3];
					sort(sum3+1,sum3+t+1);
					tx3+=1;
				} else {
					if(a[i][3]>sum3[3]) {
						sum3[1] = 0;
						sum3[1] = a[i][3];
						sort(sum3+1,sum3+t+1);
					}
				}
				
			}
			for(int l=1;l<=t;++l){
				num += sum3[l];
				num += sum1[l];
				num += sum2[l];
			}
			cout<<num<<endl;
		}
	}

	return 0;
}
