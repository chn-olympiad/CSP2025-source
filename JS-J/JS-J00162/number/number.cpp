#include <bits/stdc++.h>
using namespace std;
#define ll long long
int sum[10];
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			sum[s[i]-'0']++;
		}
	}
	for(int i=9;~i;i--)
	{
		while(sum[i]--)putchar('0'+i);
	}
	return 0;
}
