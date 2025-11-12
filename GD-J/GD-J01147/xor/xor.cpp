#include <bits/stdc++.h>
using namespace std;
int box[2000001];
int a[500001] , s[500001] , dp[500001];
int main()
{
	freopen("xor.in" , "r" , stdin); 
	freopen("xor.out" , "w" , stdout);
	int n , k , ans = 0;
	cin >> n >> k;
	memset(box , -1 , sizeof box);
	box[0] = 0;
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
		s[i] = s[i - 1] xor a[i];
		dp[i] = dp[i - 1];
		if(box[k xor s[i]] != -1)dp[i] = max(dp[i - 1] , dp[box[k xor s[i]]] + 1);
		box[s[i]] = i;
		ans = max(ans , dp[i]);
	}
	cout << ans << endl;
	return 0;
}
