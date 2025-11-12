#include<iostream>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=0;
	cin>>t;
	int r[t+1]={0};
	for(int z=0;z<t&&t>=1&&t<=5;z++){
		int n;
		cin>>n;
		if(2<=n&&n<=1e5&&n%2==0){
			int a[n+1][3];
			for(int i=0;i<n;i++){//hang
				for(int j=0;j<=2;j++){//lie
					cin>>a[i][j];
				}
			}
			int m[10]={0};
			int emax=0;
			int n_2=n/2;
			int b1=0,b2=0,b3=0;
			for(int i=0;i<n;i++){//hang
				for(int j=0;j<=2;j++){//lie
					m[i]=max(m[i],a[i][j]);
				}
				if(a[i][0]==m[i])
					b1++;
				else if(a[i][1]==m[i])
					b2++;
				else if(a[i][2]==m[i])
					b3++;
				if(b1<=n_2&&b2<=n_2&&b3<=n_2)
					emax+=m[i];	
				else{
					
				}
			}
			r[z]=emax;
		}
	}
	for(int i=0;i<t;i++){
		cout<<r[i];
		cout<<endl;
	}
	return 0;
}
