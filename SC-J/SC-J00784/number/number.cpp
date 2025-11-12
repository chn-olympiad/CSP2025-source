#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+10;

ll n,ans[100];
char a[N];
string s;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	n=s.size();
	for(int i=1;i<=n;i++)
	{
		a[i]=s[i-1];
		if(a[i]>='0' && a[i]<='9')
		{
			ll x=a[i]-'0';
			ans[x]++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int o=1;o<=ans[i];o++)
		{
			cout << i;
		}
	}
	
	return 0;
}