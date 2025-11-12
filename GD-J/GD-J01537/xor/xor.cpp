#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, k, a[500005], s[500005], id=1, ans;
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i=1; i<=n; i++){
		cin >> a[i];
		s[i]=s[i-1]+a[i];
	}
	for(int i=1; i<=n; i++){
		while(id<i&&((s[i]-s[id-1])&1)!=k) id++;
		if(((s[i]-s[id-1])&1)==k){
			id=i+1; ans++;
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
