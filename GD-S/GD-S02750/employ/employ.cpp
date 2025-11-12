#include<bits/stdc++.h>
#define ll long long
#define maxn 505
#define mod 998244353
using namespace std;
ll n,m;
string s;
ll cx[maxn],a[maxn];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(ll i=0;i<n;i++){
		cin>>cx[i];a[i]=i;
	}
	ll res=0;
	do{
		ll tot=n;ll cnt=0;
		for(ll i=0;i<n;i++){
			if(s[i]=='0'||cnt>=cx[a[i]]){
				tot--;cnt++;
			}
		}
		if(tot>=m)res=(res+1)%mod;
	}while(next_permutation(a,a+n));
	cout<<res<<"\n";
	return 0;
} 
