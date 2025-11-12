#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m, exam[105] = {0}, i = 1, j = 1, k = 1, R;
bool cmp(ll a, ll b)
{
	return a > b;
}
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout); 
	scanf("%lld %lld", &m, &n);
	ll len_list = n * m;
	for(int i = 1; i <= len_list; i++)
		scanf("%lld", &exam[i]);
	R = exam[1];
	sort(exam + 1, exam + len_list + 1, cmp);
//	for(int i = 1; i <= len_list; i++)
//		cout << exam[i] << " ";
	while(i <= n && j <= m && k <= len_list)
	{
		if(exam[k] == R)
		{
			printf("%lld %lld", i, j);
			break;
		}
		if(i % 2 != 0 && j < n)
		{
			j++;
			k++;
		}
		else if(i % 2 == 0 && j > 1)
		{
			j--;
			k++;
		}
		else
		{
			i++;
			k++;
		}		
	}
	return 0;
}

