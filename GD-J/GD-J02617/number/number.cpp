#include <bits/stdc++.h>
using namespace std;
int a[1010],j=0;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int l = s.length();
	for(int i = 0;i<l;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[++j]=s[i]-'0';
		}
	}
	sort(a+1,a+j+1,cmp);
	for(int i = 1;i<=j;i++)
	{
		cout << a[i];
	}
	return 0;
}
