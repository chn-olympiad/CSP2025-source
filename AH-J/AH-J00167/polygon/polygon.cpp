#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[5005],maxx=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(i,maxx);
	}
	if(n==3){
		if(a[1]+a[2]>a[3] && a[1]+a[3]>a[2] &&a[3]+a[2]>a[1] )
		cout<<1;
		else cout<<0;
	}
	if(maxx=1){
		ll a=0,b=1;
		for(int i=3;i<=n;i++){
			b=1;
			for(int j=1;j<=i;j++){
				b*=(n-j+1);
				b%=998244353;
				b/=j;
			}
			a+=b;
			a%=998244353;
		}
		cout<<a;
	}
	return 0;
}
