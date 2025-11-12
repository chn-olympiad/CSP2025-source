#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+5;

string s;
int a[N];
ll n;

bool isn(char x)
{
	if(x >= 'a' && x <= 'z')
		return 0;
	return 1;
}

int tu(char x)
{
	return x - '0';
}

bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s;
	for(int i = 0;i < s.size();i++)
	{
		if(isn(s[i]))
		{
			a[++n] = tu(s[i]);
		}
	}
	sort(a+1,a+n+1,cmp);
	for(int i = 1;i <= n;i++)
	{
		cout << a[i];
	}
	return 0;
}
