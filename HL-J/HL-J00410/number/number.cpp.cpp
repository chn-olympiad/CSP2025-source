#include<bits/stdc++.h>
using namespace std;
int a[1000100];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	getline(cin,s);
	int cnt=1;
	for(int i=0;i<=s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[cnt]=s[i];
			cnt++;
		}
	}
	sort(a+1,a+cnt+1);
	for(int i=cnt;i>=2;i--)
	{
		cout<<char(a[i]);
	}
	return 0;
}
