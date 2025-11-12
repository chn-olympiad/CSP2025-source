#include<bits/stdc++.h>
using namespace std;
const long long int N = 5 * 1e5 + 5;
char b[N];
int v[N];
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string s;
	cin >> s;
	int sum = 1;
	int w = s.size();
	char a[w];
	for(int i = 1; i <= s.size(); i++)
	{
		a[i] = s[i];
		if(a[i] >= 48 && a[i] <= 57)
		{
			b[sum] = a[i];
			sum++;
		}
	}
	int big = 0;
	for(int i = 1; i <= sum; i++)
	{
		for(int j = 1; j <= sum; j++)
		{
			if(b[i] > b[j])
			{
				big = b[i];
				b[i] = b[j];
				b[j] = big;
			
			}
		}
	}
	for(int i = 1; i <= sum; i++)
	{
		cout << b[i];
	}
	return 0;
}
