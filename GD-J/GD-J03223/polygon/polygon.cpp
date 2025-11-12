#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
const ll MOD=998244353;
using namespace std;
ll n;
int a[5010],b[5010];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;++i){
		cin>>a[i];
		b[a[i]]++;
	}
	if(n<=2) cout<<"0";
	else if(n==3){
		ll mx=max(a[1],max(a[2],a[3]));
		ll mn=min(a[1],min(a[2],a[3]));
		ll mid=a[1]+a[2]+a[3]-mx-mn;
		if(mx-mn>=mid) cout<<"0";
		else cout<<"1";
	}
	else cout<<"0";
	
	return 0;
} 
