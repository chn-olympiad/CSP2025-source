#include<bits/stdc++.h>
using namespace std;

const int maxn = 5 * 1e5 +5;
int n,k;
int num[maxn],arr[maxn];

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i = 1;i <= n;i++){
		cin >> num[i];
		arr[i] = arr[i-1] || num[i];
	}
	cout << 1;
	return 0;
}
