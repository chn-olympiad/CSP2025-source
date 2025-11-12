#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,a[10001][10001],cnt1=0,cnt2=0,cnt3=0;
	int sum1=0,sum2=0,sum3=0,sum4=0;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=3;++i){
			for(int j=1;j<=n;++j){
				cin>>a[i][j];
			}
		}
		for(int i=1;;){
			for(int j=1;j<=n;++j){
				if(a[i][j]>a[i+1][j]&&a[i][j]>a[i+2][j]){
					cnt1++;
					if(cnt1<=(n/2)){
						sum1+=a[i][j];
					}
				}else if(a[i+1][j]>a[i][j]&&a[i+1][j]>a[i+2][j]){
					cnt2++;
					if(cnt2<=(n/2)){
						sum2+=a[i+1][j];
					}
				}else{
					cnt3++;
					if(cnt3<=(n/2)){
						sum3+=a[i+2][j];
					}
				}
			}
		}
		sum4=sum1+sum2+sum3;
		cout<<sum4<<endl;
	}
	 
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
