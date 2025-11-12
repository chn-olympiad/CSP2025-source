#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n>=20&&n<=5000){
		for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				int x=a[k]*2;
				if(a[i]+a[j]+a[k]>x){
					cnt++;
				}
				x=0;
				
			}
		}
	}
	int num=0;
	for(int i=n;i>=1;i--){
		num+=i;
	}
	cout<<num+cnt;
	return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				int x=a[k]*2;
				
				//cout<<numm<<" ";
				if(a[i]+a[j]+a[k]>x){
					//cout<<i<<j<<k<<endl;
					cnt++;
				}
				x=0;
				
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int l=k+1;l<=n;l++){
				int x=a[l]*2;
				//cout<<numm<<" ";
				if(a[i]+a[j]+a[k]+a[l]>x){
					//cout<<i<<j<<k<<l<<endl;
					cnt++;
				}
			x=0;
				}
				
			}
		}
	}
	//5 2 2 3 8 10

		for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int l=k+1;l<=n;l++){
					for(int m=l+1;m<=n;m++){
						
							int x=a[m]*2;
				
				//cout<<numm<<" ";
				if(a[i]+a[j]+a[k]+a[l]+a[m]>x){
					//cout<<i<<j<<k<<l<<m<<endl;
					cnt++;
				}
			
				x=0;
					}
				}
				
			}
		}
	}
	//cout<<cnt;
	//return 0;
			for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int l=k+1;l<=n;l++){
					for(int m=l+1;m<=n;m++){
						for(int o=m+1;o<=n;o++){
						int x=a[o]*2;	
				
				//cout<<numm<<" ";
				if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]>x){
					//cout<<i<<j<<k<<endl;
					cnt++;
				}
				x=0;
			}
					}
				}
				
			}
		}
	}
		for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int l=k+1;l<=n;l++){
					for(int m=l+1;m<=n;m++){
						for(int o=m+1;o<=n;o++){
							for(int p=o+1;p<=n;p++){
							
						int x=a[p]*2;	
				
				//cout<<numm<<" ";
				if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]>x){
					//cout<<i<<j<<k<<endl;
					cnt++;
				}
				x=0;
			}
			}
					}
				}
				
			}
		}
	}
for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int l=k+1;l<=n;l++){
					for(int m=l+1;m<=n;m++){
						for(int o=m+1;o<=n;o++){
							for(int p=o+1;p<=n;p++){
								for(int q=p+1;q<=n;q++){
								
							
						int x=a[q]*2;	
				
				//cout<<numm<<" ";
				if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]>x){
					//cout<<i<<j<<k<<endl;
					cnt++;
				}
				x=0;
			}
			}
			}
					}
				}
				
			}
		}
	}
for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int l=k+1;l<=n;l++){
					for(int m=l+1;m<=n;m++){
						for(int o=m+1;o<=n;o++){
							for(int p=o+1;p<=n;p++){
								for(int q=p+1;q<=n;q++){
									for(int r=q+1;r<=n;r++){
									
							
						int x=a[r]*2;	
				
				//cout<<numm<<" ";
				if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]>x){
					//cout<<i<<j<<k<<endl;
					cnt++;
				}
				x=0;
			}
			}
			}
			}
					}
				}
				
			}
		}
	}
for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int l=k+1;l<=n;l++){
					for(int m=l+1;m<=n;m++){
						for(int o=m+1;o<=n;o++){
							for(int p=o+1;p<=n;p++){
								for(int q=p+1;q<=n;q++){
									for(int r=q+1;r<=n;r++){
										for(int s=r+1;s<=n;r++){
										
							
						int x=a[s]*2;	
				
				//cout<<numm<<" ";
				if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[s]>x){
					//cout<<i<<j<<k<<endl;
					cnt++;
				}
				x=0;
			}
			}
			}
			}
					}
				}
				
			}
		}
	}
}
cout<<cnt;
return 0;
}
//5 1 2 3 4 5

