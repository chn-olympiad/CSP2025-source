#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int man=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>man) man=a[i];
	}
	sort(a+1,a+1+n);
	if(n<=3){
		if(n<=2){
			cout<<0;
		}
		else{
			if(a[1]+a[2]>a[3]){
				cout<<1;
			}
			else{
				cout<<0;
			}
		}
		return 0;
	}
	if(man<=1){
		long long sum=0;
		for(int i=3;i<=n/2;i++){
			long long y=1,x=1;
			for(int j=n;j>=n-i+1;j--){
				if(j==i) break;
				y=y*j;
			}
			for(int j=i;j>=1;j--){
				if(j>=n-i+1) continue;
				x=x*j;
			}
			sum=(sum+y/x)%998244353;
		}
		sum=(sum*2+n+n*(n-1)+1)%998244353;
		
		cout<<sum;
	}
	return 0;
}
