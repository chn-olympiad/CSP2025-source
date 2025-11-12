#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int cnt = 0;
	for(int i = 0;i < int(s.size());i++)
	{
		if((int(s[i]) >= 97 && int(s[i]) <= 122))
		{
			continue;
		}
		else
		{
			cnt++;
			a[cnt] = s[i] - '0';
		}
	}
	sort(a+1,a+cnt+1);
	for(int i = cnt;i >= 1;i--)
	{
		cout<<a[i];
	}
	return 0;
}
