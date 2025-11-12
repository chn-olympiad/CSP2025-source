#include<bits/stdc++.h>
#define  ll  long long
using namespace std;
const int N=INT_MAX;
ll n,a[50005],cnt=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll i=1;i<=n-2;i++){
		ll sum,maaa=0;
		for(ll k=i;k<=i+2;k++){
		    sum+=a[k];
			maaa=max(maaa,a[k]);
		}
		if(sum>maaa*2)cnt++;
	}
	cout<<cnt;
	return 0;
}
