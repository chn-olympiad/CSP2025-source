#include<bits/stdc++.h>
using namespace std;
int n,t;
int a[1000005][5];
int b[1000005];
int d[100005];
int f;
int f1;
int c[100005];
int sum;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(j==2){
					if(a[i][j]!=0){
						f=1;
						//break;
					}
				}
				else if(j==3){
					if(a[i][j]!=0){
						f1=1;
					///break;
					}
				}
			}			
		}
		if(f==0&&f1==0){
			for(int i=1;i<=n;i++){
				b[i]=a[i][1];
			}
			sort(b+1,b+1+n);
			for(int i=n;i>(n/2);i--){
				sum+=b[i];
			}
			cout<<sum<<endl;
			sum=0;
		}
		sum=0;
		f=0;
		if(n==2){
			int sum1=a[1][1]+a[2][2];
			int sum2=a[1][1]+a[2][3];
			int sum3=a[1][2]+a[2][3];
			int sum4=a[1][2]+a[2][1];
			//cout<<a[1][1]<<" "<<a[2][2]<<endl;
			int sum5=a[1][3]+a[2][2];
			int sum6=a[1][3]+a[2][1];
			//cout<<sum1<<" "<<sum2<<" "<<sum3<<" "<<sum4<<" "<<sum5<<" "<<sum6<<endl;
			int sum=max(max(max(max(max(sum1,sum2),sum3),sum4),sum5),sum6);
			cout<<sum<<endl;
			sum=0;
		}
		else if(f==0||f1==0){
			int sum=0;
			int sum1=0;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=2;j++){
					if(a[i][1]>a[i][2]){
						b[i]=a[i][1];
						c[i]=1;
					}
					else{
						d[i]=a[i][2];
						c[i]=2;
					}
				}
			}
			for(int i=1;i<=n;i++){
				if(c[i]==1){
					sum+=c[i];
				}
				else{
					sum1+=c[i];
				}
			}
			if(sum<=n/2&&sum1<=n/2){
				cout<<sum+sum1<<endl;
			}
			else{
				sort(b+1,b+1+n);
				sort(c+1,c+1+n);
				for(int i=n;i>n/2;i--){
					sum+=b[i];
					sum+=c[i];
				}
				cout<<sum<<endl;
				
			}
		}
		else if(n==4){
			int sum1=max(max(a[1][2],a[1][3]),a[1][1]);
			int sum2=max(max(a[2][2],a[2][3]),a[2][1]);
			int sum3=max(max(a[3][2],a[3][3]),a[3][1]);
			int sum4=max(max(a[4][2],a[4][3]),a[4][1]);
			cout<<sum1+sum2+sum3+sum4;
			
		}
		else{
			int ans=0;
			int sum=0;
			int sum1=0,sum2=0;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=3;j++){
					if(a[i][1]>a[i][2]&&a[i][1]>a[i][3]){
						c[i]=a[i][1];
						b[i]=1;
					}
					else if(a[i][2]>a[i][1]&&a[i][2]>a[i][3]){
						c[i]=a[i][2];
						b[i]=2;
					}
					else{
						c[i]=a[i][3];
						b[i]=3;
					}
	
				}
			}
			for(int i=1;i<=n;i++){
				if(b[i]==1){
					sum+=b[i];
				}
				else if(b[i]==2){
					sum1+=b[i];
				}
				else{
					sum2+=b[i];
				}
				if(sum<=n/2&&sum1<=n/2&&sum2<=n/2){
					ans=sum+sum1+sum2;
				}
			}
			cout<<ans<<endl;
			ans=0;
			sum=0;
			sum1=0;
			sum2=0;
			
		}
	}
	return 0;
}
