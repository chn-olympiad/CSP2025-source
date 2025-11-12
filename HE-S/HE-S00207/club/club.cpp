#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int a[100100][5];
int max1,max2,max3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int num1=0;
		int num2=0;
		int num3=0;
		cin>>n;
		bool XXX=false;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(a[i][2]==0||a[i][3]==0){
					XXX=true;
				}
			}
		}
		if(n<=30&&XXX==false){
			int maxnum=n/2;
			for(int i=0;i<maxnum;i++){
				
			}
			for(int i=1;i<=n;i++){
				int gr=1;
				int mlove=a[i][1];
				if(max(a[i][1],max(a[i][2],a[i][3]))==a[i][1]&&num1+1<=n/2){
					gr=1;
					max1+=a[i][1];
					num1++;
				}
				if(a[i][2]>a[i][1]&&num2+1<=n/2){
					gr=2;
					max2+=a[i][2];
					num2++;
				}else if(a[i][3]>a[i][2]&&num3<=n/2){
					gr=3;
					max3=a[i][3];
					num3++;
				}					
			}
			cout<<max1<<endl;
			cout<<max2<<endl;
			cout<<max3<<endl;
		}else if((n>=500&&n<=10000)&&XXX==true){
				  int maxxx=a[1][1];
				  for(int i=0;i<n;i++){
					if(a[i][1]>=maxxx){
						maxxx=a[i][1];
						a[i][1]=0;
						if(num1+1<=n/2){
							max1+=maxxx;
							num1++;
						}
					}
				}
			}
		}
		
	return 0;
}
