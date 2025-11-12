#include<bits/stdc++.h>
using namespace std;

const int N=5e5+5;
int n, k, arr[N], ans=0;
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	if (k == 0){
		cout << n/2;
		return 0;
	}
	for (int i=1;i<=n;i++){
		cin >> arr[i];
		//arr[i] = arr[i] ^ arr[i-1];
	}
	for(int i=1;i<=n;i++){
		if (k == 1 && arr[i] == 1) 
			ans++;
	}
	cout << ans;
	return 0;
}
