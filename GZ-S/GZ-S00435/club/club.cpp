//GZ-S00435 邓愚山 贵阳市第十八中学
#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	int n,a1,a2,a3,sum=0,yi=0,er=0,san=0,mina1=9999999999999,mina2=999999999999,mina3=99999999999,k1,k2,k3,ban;
	cin>>t;
	for(int i=1; i<=t; i++) {
		cin>>n;
		yi=0;
		er=0;
		san=0;
		ban=n/2;
		for(int i=1; i<=n; i++) {
			cin>>a1>>a2>>a3;
			if(a1>a2&&a1>a3) {
				sum+=a1;
				if(a1<mina1) mina1==a1,k1=max(a1,a2);
				yi++;
				if(yi>ban) {
					sum-=mina1;
					sum+=k1;
					yi--;
					if(a2>a3){
						san++;
					}else if(a3>a2){
						er++;
					}else if(a3==a2){
						if(san>er){
							er++;
						}
						if(er>san){
							san++;
						}
					}
				}
			} else if(a2>a1&&a2>a3) {
				sum+=a2;
				if(a2<mina2) mina2==a2,k2=max(a1,a3);
				er++;
				if(er>ban) {
					sum-=mina2;
					sum+=k2;
					er--;
					if(a1>a3){
						san++;
					}else if(a3>a1){
						yi++;
					}else if(a3==a1){
						if(san>yi){
							yi++;
						}
						if(yi>san){
							san++;
						}
					}
				}
			} else if(a3>a1&&a3>a2) {
				sum+=a3;
				if(a3<mina3) mina3==a3,k3=max(a3,a2);
				san++;
				if(san>ban) {
					sum-=mina3;
					sum+=k3;
					san--;
					if(a1>a2){
						er++;
					}else if(a2>a1){
						yi++;
					}else if(a2==a1){
						if(yi>er){
							er++;
						}
						if(er>yi){
							yi++;
						}
					}
				}
			}
		}
		cout<<sum<<endl;
		mina1=99999999;
		mina2=99999999;
		mina3=99999999;
		yi=0;
		er=0;
		san=0;
		sum=0;
	}
	return 0;
}
