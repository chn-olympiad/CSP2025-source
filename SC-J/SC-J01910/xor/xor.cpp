#include<bits/stdc++.h>
#define ll long long
using namespace std;
int const N=5e5+5;
ll n,k,a[N],s[N],ans,ls;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i=1;i<=n;i++)
		cin>>a[i],s[i]=s[i-1]^a[i];
	for(ll i=1;i<=n;i++)
		for(ll j=i;j>ls;j--)
			if((s[i]^s[j-1])==k){
				ans++,ls=i;
				break;
			}
	cout<<ans;
	return 0;
}