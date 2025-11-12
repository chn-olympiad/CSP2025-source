#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,s[5005],sum[5005],sum;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>s[i];
		sum[i]=sum[i-1]^s[i];
	}
	for(ll l=1;l<=n;l++) for(ll r=1;r<=n;r++) if(sum[r]^sum[l]==m) sum++;
	cout<<sum;
	return 0;
}
