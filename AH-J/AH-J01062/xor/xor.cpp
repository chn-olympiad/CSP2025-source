#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+10;
ll n,k;
ll cnt0,cnt1;
ll a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0)	cnt0++;
		if(a[i]==1)	cnt1++;
	}
	if(k==1){
		cout<<cnt1;
	}
	else if(k==0){
		if(cnt0!=0)	cout<<cnt0;
		else cout<<cnt1/2;
	}
	return 0;
}
