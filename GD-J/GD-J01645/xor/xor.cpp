#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+10;
ll n,k,maxn,a[N]; 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=1;i<=n/2;i++) maxn=max(maxn,a[i]);
	cout<<maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
