#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	int a[105];
	if(n<3){
		return 0;
	}
	int cnt=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
						if(a[i]+a[j]>a[k]&&a[i]+a[k]>a[j]&&a[j]+a[k]>a[i])cnt++;
						
					}
				}	
			}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				for(int f=1;f<=n;f++)
						if(i<=j&&j<=k&&k<=f)cnt++;
						
					}
				}	
			}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				for(int f=1;f<=n;f++){
					for(int g=1;g<=n;g++)
						if(i<=j&&j<=k&&k<=f)cnt++;
						}	
					}
				}	
			}
	cout<<cnt; 
	return 0; 
} 
