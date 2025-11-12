#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int A[5010],cnt[5010];
int main(){
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++)cin >> A[i];
	sort(A + 1,A + 1 + n);
	for(int i = 1;i <= n;i++){
		for(int j = i - 1;j > 0;j--)cnt[i] = (cnt[i] + cnt[j]) % mod;
		cnt[i] += i - 1;
		cnt[i] %= mod;
	}
	cout << cnt[n] - cnt[n - 1] + 1;
	
	return 0;
}
