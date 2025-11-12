#include<bits/stdc++.h>
using namespace std;
long long n,a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int i;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	long long ans;
	sort(a+1,a+n+1);
	ans=a[1]*a[5]/a[7]+a[8]-a[14]+a[1089];
	ans%=366911923; 
	cout<<ans;
	return 0;
}
