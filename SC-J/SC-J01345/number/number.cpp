#include<bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a[1000020],b=1;
	for(int i = 0;i<s.length();i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			a[b]=s[i]-'0';
			b++;
		}
	}
	sort(a+1,a+b);
	for(int i = b-1;i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
}
