/*
#include<bits/stdc++.h>
using namespace std;
const int M = 5e5 + 5;
int a[M];
int main()
{
	freopen("xor.in" , "r" , stdin);
	freopen("xor.out" , "w" , stdout);
	int n , k;
	cin >> n >> k;
	for(int i = 1 ; i <= n ; i++)
		cin >> a[i];
	int flag = true;
	for(int i = 1 ; i <= n ; i++)
		if(a[i] != 1)
		{
			flag = false;
			break;
		}
	if(flag && k == 0)
	{
		cout << n / 2;
		return 0;
	}
	return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;
const int M = 5e5 + 5;
int f[M] , a[M] , s[M];
int main()
{
	freopen("xor.in" , "r" , stdin);
	freopen("xor.out" , "w" , stdout);
	int n , k;
	cin >> n >> k;
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
		s[i] = s[i - 1] ^ a[i];
	}
	for(int i = 1 ; i <= n ; i++)
	{
		if(s[i] == k)
			f[i] = -1;
		f[i] = max(f[i] , f[i - 1]);
		f[i] = max(f[i] , f[i - s[i]] + 1);
	}
	cout << f[n];
	return 0;
}
