#include <bits/stdc++.h>
using namespace std;
int t;
int n,nn;
int sum;
int a[15][105];
int f[15][105];
int maxx=-1;
int a1,a2,a3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		sum=0;
		a1=0;
		a2=0;
		a3=0;
		maxx=-1;
		cin>>n;
		nn=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[1][i]>>a[2][i]>>a[3][i];
		}
		for(int i=1;i<=n;i++){
			for(int ii=1;ii<=3;ii++){
				for(int j=1;j<=n;j++){
					if(a1<=nn&&a2<=nn&&a3<=nn){
						sum+=a[ii][j];
						if(ii==1){
							a1++;
						}
						else if(ii==2){
							a2++;
						}
						else if(ii==3){
							a3++;
						}
						//cout<<"look"<<a[ii][j]<<endl;
					}
				}
				if(maxx<=sum){
					maxx=sum;
				}
				sum=0;
			}
		}
		cout<<maxx<<endl;
	}
	return 0;
}