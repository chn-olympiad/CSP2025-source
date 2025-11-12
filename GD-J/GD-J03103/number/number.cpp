#include <bits/stdc++.h>
using namespace std;
#define ll long long
char s[1000000];
vector<ll> a;
bool cmp(ll a, ll b)
{
	return a > b;
}
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout); 
	scanf("%s", &s);
	ll len_s = strlen(s);
	for(ll i = 0; i < len_s; i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			a.push_back(s[i] - '0');
		}
	}
	sort( a.begin(), a.end(), cmp); 
	for(auto i : a)
	{
		printf("%lld", i);
	}
	return 0;
}

