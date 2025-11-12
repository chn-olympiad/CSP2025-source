#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,a[10010],sum=0,maxi=0,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		if(a[i]>maxi){
			maxi=a[i];
		}
	}
	if(sum>2*maxi){
		ans++;
	}
	cout<<ans%998244353;
	return 0;
}
