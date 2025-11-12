#include <bits/stdc++.h>
using namespace std;
string s;
int x,a[1000005];
bool cmp(int j,int k)
{
	return j>k;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i=0;i<s.length();i++)
	{
		if(isdigit(s[i]))
		{
			a[++x]=int(s[i]-'0');
		}
	}
	sort(a+1,a+1+s.length(),cmp);
	for(int i=1;i<=x;i++)
		cout << a[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
