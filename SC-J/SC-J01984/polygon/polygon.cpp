#include<bits/stdc++.h>
using namespace std;
int n,a[5010],max1,max2;
long long ans,sum[5010];
int main(){
	cin>>n;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
		max1=max(max1,a[i]);
	}
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		if(sum[n]>2*max1){
			cout<<1;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}
	
	if(n>3){
		for(int j=1;j<=n;j++){
			for(int i=j;i<=n;i++){
				max2=max(max2,a[i]);
				if(sum[i]>2*max2&&i>=3){
					ans++;
				}
			}
		}
		cout<<ans%998244353;
		return 0;
		
	}
	
	
	return 0;
} 