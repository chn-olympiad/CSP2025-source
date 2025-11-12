#include<bits/stdc++.h>
using namespace std;
int n,a[5005],sum;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==3){
		sort(a+1,a+n+1);
		if(a[1]+a[2]>a[3])cout<<1<<endl;
		else cout<<0<<endl;
	}
	else{
		int k=1;
		for(int i=3;i<=n;i++){
			sum=(sum+k)%998244353;
			k+=(i-1);
		}
		cout<<sum<<endl;
	}
	
	return 0;
}
