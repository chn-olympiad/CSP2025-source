#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
long long numm;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int len=s.length();
	for(int i=0;i<len;i++)
	{
		if('0'<=s[i]&&s[i]<='9')
		{
			a[i]=s[i]-'0';
			numm++;
		}
	}
	sort(a,a+len+1,cmp);
	for(int i=0;i<numm;i++)
	{
		cout << a[i];
	}
	return 0;
}
