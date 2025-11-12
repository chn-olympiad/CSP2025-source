#include<bits/stdc++.h>

using namespace std;

int n,k,a[500005],b[5000006],f[500005],now,ans;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> k;
	for(int i = 1;i <= n;i++)cin >> a[i];
	for(int i = 0;i <= n;i++){
		now ^= a[i];
		b[now] = i + 1;
		int j = b[now ^ k];
		f[i] = f[i - 1];
		if(j)f[i] = max(f[i],f[j - 1] + 1),ans = max(ans,f[i]);
	}
	cout << ans << endl;
	return 0;
}
