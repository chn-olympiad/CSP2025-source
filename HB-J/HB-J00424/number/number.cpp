#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e3+7;
string s;
ll a[N];
ll cnt;
ll size(string s){
	ll i=0;
	while(1)
	{
		if(s[i])i++;
		else break;
	}
	return i;
}

bool cmp(ll x,ll y)
{
	return x > y;
}

int main()
{
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin >> s;
	ll t=0;
	for(ll i = 0;i < size(s);i++)
	{
		if(s[i] >= '0' and s[i] <= '9')
		{
			a[t] = s[i] - '0';
			cnt++;
			t++;
		}
	}
	sort(a,a+cnt,cmp);
	for(ll i = 0;i < cnt ;i++)
	{
		cout << a[i];
	}	


	return 0;
}
