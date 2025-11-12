#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n,k,ans;
ll a[N];// 2^20=1048576
inline bool chk(ll x)
{
	int he=0,f=0;
	for(int i=1;i<=n;i++)
	{
		he^=a[i];
		if(he==k){
			he=0;
			f++;
		}
	}
	if(f>=x) return true;
	return false;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	ll l=0,r=n;
	while(l<r){
		ll mi=((l+r)>>1)+1;
		if(chk(mi)){
			ans=mi;
			l=mi;
		}
		else{
			r=mi-1;
		}
	}
	cout<<ans;
	return 0;
}
