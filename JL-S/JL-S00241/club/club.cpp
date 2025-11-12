#include<bits/stdc++.h>
using namespace std;
long long a[100005][3];
long long b[1000];
long long maxx[1000];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t,n,max=0,sum=0,c=0,d=0;
	cin>>t;
	for(int k=1;k<=t;k++){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				
			}
			
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				if(max<a[i][j]){
					max=a[i][j];

				}
				c++;
				if(c==3){

					if(a[i][3]>a[i][2]&&a[i][3]>a[i][1]){
						b[3]++;
						if(a[i][2]>a[i][1]){
							maxx[2]=a[i][2];
						}else{
							maxx[1]=a[i][1];
						}
						
					}
					else if(a[i][3]>a[i][2]&&a[i][3]<=a[i][1]){
						b[1]++;
						maxx[3]=a[i][3];
						
						
					}
					else if(a[i][3]<=a[i][2]&&a[i][1]<=a[i][2]){
						b[2]++;
						if(a[i][3]>a[i][1]){
							maxx[3]=a[i][3];
						}else{
							maxx[1]=a[i][1];
						}
					}
					else{
						b[1]++;
					}
					if(a[1][3]==0){
						sum=sum-maxx[j];
					}
				}
				
			}c=0;
			for(int j=1;j<=3;j++){
				if(b[j]*2<=n){
					d++;
				}
				else{
					sum=sum+maxx[j];
					max=0;
					d++;
				}
			}
			if(d==3){
				sum=sum+max;
			}
			d=0;
			max=0;
			
		}
		cout<<sum<<endl;
		sum=0;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(maxx,0,sizeof(maxx));
	}
	return 0;
}
