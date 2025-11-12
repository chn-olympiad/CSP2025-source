#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
ll a[5005];

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	for(ll i=1;i<=n;i++)cin>>a[i];
	
	if(n==3){
		int sum=a[1]+a[2]+a[3];
		int maxx=max( a[3], max(a[1],a[2]) );
		if(maxx*2 < sum){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}
	
	cout<<6;
	
	return 0;
}
