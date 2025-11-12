#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
ll z[N],s[N],sum,a;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	ll n,k;
	cin>>n>>k;
	for(ll i=1;i<=n;i++){
		cin>>z[i];
		s[i]=s[i-1]^z[i];
	}
	a=0;
	for(ll i=1;i<=n;i++){
		if(z[i]==k){
			sum++;
			a=i;
			continue;
		}
		for(ll j=a;j<i;j++){
			ll b=s[i]^s[j];
			if(b==k){
				a=i;
				sum++;
				break;
			}
		}
	}
	cout<<sum;
	return 0;
}