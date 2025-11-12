#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
char c[N];
int cnt[10], n;
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> c;
	n = strlen(c);
	for(int i = 0; i < n; i++)
		if(c[i] >= '0' && c[i] <= '9')
			cnt[c[i] - '0']++;
	for(int i = 9; i >= 0; i--)
		while(cnt[i] > 0) 
		{
			cout << i;
			cnt[i]--;
		}
	return 0;
}
