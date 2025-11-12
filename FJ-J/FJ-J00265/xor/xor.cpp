#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k,a[500100],ans = 0,f[500100];
void solve1(){
	for (ll i = 2;i <= n;i++){
		if (f[i] == 1) continue;
		ll s = a[i],m = 0,j = i - 1;
		for (;j >= 1;j--){
			if (f[j] == 1) break;
			s ^= a[j];
			if (s == k){m = 1,ans++;break;}
		 }
		if (m == 0) continue;
		for (;j <= i;j++) f[j] = 1;
	 }
 }
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i = 1;i <= n;i++) {
		cin>>a[i];
		if (a[i] == k) f[i] = 1,ans++;
	 }
	solve1();
	cout<<ans;
	return 0;
 }
