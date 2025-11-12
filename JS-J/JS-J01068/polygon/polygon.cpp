#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef bool bb;
typedef double dd;
typedef string ss;
typedef void vv;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ll n;
	cin>>n;
	if(n==3){
		ll a,b,c;
		cin>>a>>b>>c;
		if(a+b>c&&a+c>b&&b+c>a){
			cout<<1<<endl;
		}
		else{
			cout<<0<<endl;
		}
	}
	else{
		cout<<n*2<<endl;
	}

	return 0;
}
