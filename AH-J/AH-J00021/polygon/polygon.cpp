#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[5010];
ll sum[5010];
ll n;
void f12(){
	if(n<3)cout<<0;
	else if(n==3){
		if(a[1]+a[2]+a[3]>2*a[3])cout<<1;
		else cout<<0;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	if(n<=3){
		f12();
		return 0;
	}
	cout<<n;
	return 0;
}
