#include<bits/stdc++.h>
using namespace std;
int n=0,a[1000010],c;
string s; 
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]<='9'&&s[i]>='0')
		{
			n++;
			a[n]=s[i]-'0';
		}
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--)
	{
		printf("%d",a[i]);
	}
	return 0;
} 