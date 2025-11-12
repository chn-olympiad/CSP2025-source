#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n;cin>>n;
	long long a[n];
	for(long long* i=a;i<a+n;i++)cin>> *i;
	sort(a,a+n);
	cout<<(a[n-1]*652)%998244353;
	return 0;
}
