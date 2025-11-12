#include<bits/stdc++.h>
using namespace std;
long long a[102400];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long sum=a[1],ans=0;
	int flag=1;
	for(int i=1;i<=n-1;i++){
		for(int j=1;j<=n-i+1;j++){
			for(int o=1;o<=i;o++){
				if(i==1){
					if(a[j]==k){
						ans=1;
					}
				}else{
					if(flag==1){
						sum=a[j+o-1];
						flag=0;
					}else{
						sum^=a[j+o-1];						
					}					
				}
			}
			if(sum==k){
				ans=i-1;				
			}
			flag=1;
		}
	}
	cout<<ans;
	return 0;
}
