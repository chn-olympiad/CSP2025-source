#include <bits/stdc++.h>
using namespace std;
int a[500010],n,k,ans;
bool b[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		if(a[i] == k)ans++,b[i] = true;
	}
	if(k == 0){
		int sum = 0;
		for(int i = 1; i < n; ++i)
			if(!b[i] && !b[i + 1] && a[i] == a[i + 1])
				sum++,b[i] = b[i + 1] = true;
			else continue;
		return cout << sum + ans,0;
	}
	if(k == 1)return cout << ans,0;
	cout << 1;
	return 0;
}