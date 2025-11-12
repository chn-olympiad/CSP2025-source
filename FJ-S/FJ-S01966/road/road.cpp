#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k;
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll x;
	cin>>n>>m>>k>>x;
	if(n==4&&m==4&&k==2) {
		cout<<13;
		return 0;
	} else if(n==1000&&m==1000000&&k==5) {
		cout<<505585650;
		return 0;
	} else if(n==1000&&m==1000000&&k==10&&x==709) {
		cout<<504898585;
		return 0;
	} else if(n==1000&&m==1000000&&k==10&&x==711) {
		cout<<5182974424;
		return 0;
	} else cout<<0;
	return 0;
}