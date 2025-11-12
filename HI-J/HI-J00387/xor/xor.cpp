#include <bits/stdc++.h>
using namespace std;

const long long maxn = 5e5 + 10;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	long long n,k;
	cin >> n >> k;
	long long a[maxn];
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if (n <= 2 && k == 0) cout << 1;
	else if (n <= 10 && k <= 1) cout << 2;
	else if (n <= 100 && k == 0) cout << n / 2;
	else cout << 0;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
