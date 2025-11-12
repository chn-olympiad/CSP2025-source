#include<bits/stdc++.h>
using namespace std;
string s;
char a[1000000];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int x=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[x]=s[i];
			x++;
		}
	}
	sort(a,a+x);
	for(int i=x;i>=0;i--)
	{
		cout<<a[i];
	}
	return 0;
}
