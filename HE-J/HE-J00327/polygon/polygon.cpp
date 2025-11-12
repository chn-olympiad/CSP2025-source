#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[100001];
	long long ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			
			int s=0;
			if(j>i){
				sort(a+i+1,a+j+1);
				for(int k=i;k<=j;k++){
					s+=a[k];
				}
			}else{
				sort(a+j+1,a+i+1);
				for(int k=j;k<=i;k++){
					s+=a[k];
				}
			}
			
			if(j>i){
				if(j-i+1>=3&&s>a[j]*2){
					ans++;
				}
			}else{
				if(i-j+1>=3&&s>a[i]*2){
					ans++;
				}
			}
			
		}
	}
	cout<<ans%998244353;
	return 0;
}

