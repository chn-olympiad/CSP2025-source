#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
int n,m,a[1000000],l,n3,oo=4;
long long jihe[7000]={0},f[5006];
bool f2=1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	f[3]=1;
	for(int i=4;i<=5000;i++){
		f[i]=f[i-1]+oo;
		oo=(oo*2+i-1)%998244353;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			f2=0;
		}
	}
	sort(a+1,a+n+1);
	if(f2==1){
		cout<<f[n];
		return 0;
	}
	long long cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int q=j+1;q<=n;q++){
				if(a[i]+a[j]>a[q]){
					cnt++;
				}
			}
		}
	}
	if(n==3){
		cout<<cnt;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int q=j+1;q<=n;q++){
				for(int a4=q+1;a4<=n;a4++){
				
					if(a[i]+a[j]+a[q]>a[a4]){
						cnt++;
					}
				}
			}
		}
	}
	if(n==4){
		cout<<cnt;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int q=j+1;q<=n;q++){
				for(int a4=q+1;a4<=n;a4++){
				
					for(int a5=a4+1;a5<=n;a5++){
						if(a[i]+a[j]+a[q]+a[a4]>a[a5]){
							cnt++;
						}
					}
				}
			}
		}
	}
	if(n==5){
		cout<<cnt;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int q=j+1;q<=n;q++){
				for(int a4=q+1;a4<=n;a4++){
				
					for(int a5=a4+1;a5<=n;a5++){
						for(int a6=a5+1;a6<=n;a6++){
							if(a[i]+a[j]+a[q]+a[a4]+a[a5]>a[a6]){
								cnt++;
							}
						}
					}
				}
			}
		}
	}
	if(n==6){
		cout<<cnt;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int q=j+1;q<=n;q++){
				for(int a4=q+1;a4<=n;a4++){
				
					for(int a5=a4+1;a5<=n;a5++){
						for(int a6=a5+1;a6<=n;a6++){
							for(int a7=a6+1;a7<=n;a7++){
								if(a[i]+a[j]+a[q]+a[a4]+a[a5]+a[a6]>a[a7]){
									cnt++;
								}
							}
						}
					}
				}
			}
		}
	}
	if(n==7){
		cout<<cnt;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
