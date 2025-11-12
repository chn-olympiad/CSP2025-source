#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,wood_length[5005];
	cin >> n;
	for(int i = 1;i <= n;i++)
		cin >> wood_length[i];
	if(n < 3)
	{
		cout << 0;
		return 0;
	}
	int max_length = -1;
	int sum_length = 0;
	for(int i = 1;i <= n;i++)
	{
		max_length = max(max_length,wood_length[i]);
		sum_length += wood_length[i];
	}
	if(n == 3 && sum_length <= max_length * 2)
	{
		cout << 0;
		return 0;
	}
	
}
