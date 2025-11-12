#include <bits/stdc++.h>
using namespace std;
int a[10005];
bool cmp(int a,int b)
{
	return a > b;                     
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n = 0;
	string s;
	cin>>s;
	for(int i = 0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[n] = s[i]-'0';
			n++;
		}
	}
	sort(a+0,a+n,cmp);
	for(int i = 0;i<n;i++)
	{
		cout<<a[i]; 
	}
	return 0;
}
