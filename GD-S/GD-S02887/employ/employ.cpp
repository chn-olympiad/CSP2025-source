#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
string str;
ll n, m;
ll a[505];
void case_n10()
{
	sort(a+1, a+1+n);
	ll i, j, res = 0, cut, cnt, t = 1, x;
	for(i = 1; i <= n; i++)
	{
		x = 1;
		for(j = i+1; j <= n; j++)
		{
			if(a[i] != a[j])
				break;
			x++;
		}
		for(j = 1; j <= x; j++)
			t *= j;
	}
	do
	{
		cut = 0;
		cnt = 0;
		for(i = 1; i <= n; i++)
		{
			if(a[i] <= cut)
				cut++;
			else if(str[i-1] == '0')
				cut++;
			else
				cnt++;
		}
		if(cnt >= m)
			res++;
	}while(next_permutation(a+1, a+1+n));
	cout << res * t;
}
void case_si1()
{
	ll res = 1, i;
	for(i = 1; i <= n; i++)
		res = res * i % mod;
	cout << res;
}
void case_m1()
{
	ll id = 0, cnt = 0, i;
	for(i = 1; i <= n; i++)
	{
		if(str[i] == '1')
		{
			id = i;
			break;
		}
	}
	if(id == 0)
	{
		cout << 0;
		return;
	}
	for(i = 1; i <= n; i++)
		if(a[i] >= id)
			cnt++;
	if(cnt == 0)
	{
		cout << 0;
		return;
	}
	ll res = cnt;
	for(i = 1; i < n; i++)
		res = res * i % mod;
	cout << res;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ll i, cnt=0;
	cin >> n >> m >> str;
	for(char ch : str)
	{
		cnt += (ch == '1');
	}
	for(i = 1; i <= n; i++)
		cin >> a[i];
	if(n <= 11)
		case_n10();
	else if(cnt == n)
		case_si1();
	else if(m == 1)
		case_m1();
	else
		cout << 0;
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
