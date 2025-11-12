#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;ll k;
	scanf("%d%lld",&n,&k);
	vector<ll> a(n+1);
	vector<int> dp(n+1,0);
	vector<ll> suffixXor(n+1,0);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		suffixXor[i]=suffixXor[i-1]^a[i];
	}
	int last = 1;
	int ans = 0;
	for(int i = 1;i <= n;i++){
		for(int j = last;j <= i;j++){
			if((suffixXor[j-1]^suffixXor[i])==k){
				ans++;
				last = i+1;
				break;
			}
		}
	}
	printf("%d",ans);
	return 0;
}