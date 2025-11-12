#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,a[5050];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long x=0;
	sort(a+1,a+n+1);
	if(n==3){
		if(a[1]+a[2]+a[3]>max(a[1],max(a[2],a[3]))*2){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}
	for(int i=n;i>=3;i--){
		int sum=a[i]+a[i-1]+a[i-2];
		if(sum>a[i]*2)x++;
		for(int j=i-3;j>=1;j--){
			sum+=a[j]; 
			if(sum>a[i]*2)x++;
			for(int m=j+1;m<=i;m++){ 
			    if(m==i-3&&j==i-3)continue;
				if(sum-a[m]>a[i]*2)x++;
			}  
		}
	}
	cout<<x%998244353;
	return 0;
} 