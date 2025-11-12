#include<bits/stdc++.h>
using namespace std;
long long w = 0;
string s;
char a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(long long i = 0;i < s.size();i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			a[w] += s[i];
			w++;
		}
	}
	sort(a+0,a+w);
	for(long long i = w-1;i >= 0;i--)
	{
		cout<<a[i];
	}
	return 0;
}
