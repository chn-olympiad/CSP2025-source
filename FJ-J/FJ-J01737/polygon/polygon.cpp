#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans,sum;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	
	if(n<=3){
		if(a[1]+a[2]>a[3])
			ans=1;
		else
			ans=0;
	}
	else if(a[1]+a[2]>a[n]){
		for(int i=3;i<=n;i++){
			sum=n;
			for(int j=n-1;j>=2;j--)
				sum=sum*j%998244353;
			for(int j=i;j>=2;j--)
				sum=(sum/j)%998244353;
			ans=(ans+sum)%998244353;
		}
	}
	else
		ans=n*n;
	cout<<ans;
	return 0;
}
