#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n , a[5005] , cnt;
void check(ll sum , ll maxn , ll p)
{
	if(sum > maxn * 2)
	{
		cnt++;
		cnt %= 998244353;
	}
	for(ll i = p + 1;i <= n;i++)
	{
		check(sum + a[i] , max(maxn , a[i]) , i);
	}
	return ;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(ll i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	check(0 , 0 , 0);
	cout << cnt;
	return 0;
}
