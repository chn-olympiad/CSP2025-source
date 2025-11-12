#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[5010]; 
long long cnt;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>n;
	}
	for(int i=1;i<=n;i++){
		if(n>=3){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					if(a[i]+a[j]>a[k]&&a[j]+a[k]>a[j]&&a[k]+a[i]>a[j]){
						long long ans=max(a[i],a[j]);
						ans=max(ans,a[k]);
						if(a[i]+a[k]+a[j]>2*ans){
							cnt++;
						}
					}
				}
			}
		}
		if(n>=4){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int o=k+1;o<=n;o++){
						long long ans=max(a[i],a[j]);
						ans=max(ans,a[k]);
						if(a[i]+a[k]+a[j]>2*ans){
							cnt++;
							}
					}
					
				}
			}
		}
	}
	cout<<cnt;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
