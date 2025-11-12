#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a,ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a;
		ans+=i;
	}
	cout<<ans-a;
	return 0;
}
