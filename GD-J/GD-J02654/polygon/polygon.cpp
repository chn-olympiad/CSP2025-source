#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
	feropen("polygon.in","r",stdin);
	feropen("polygon.out","w",stdout);
	int n;
	long long ans=0;
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	if(n=3){
		sort(a+1,a+n+1);
		if(a[1]+a[2]>a[3])ans++;
	}
	else{
		for(int i=3;i<=n;i++){
		
		long long z=1;
		for(int j=n;j>=n-i+1;j--){
			z*=j;
		}
		
		for(int j=1;j<=i;j++){
			z/=j;
		}
		ans+=z;
		ans%=998244353;
		}
	}
	cout<<ans;
	return 0;
}
