#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int a[1000001],n;
	cin>>s;
	int ls=s.size();
	for(int i=0;i<ls;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[n]=s[i]-'0';
			n++;
		}
	}
	sort(a,a+n);
	for(int i=n-1;i>=0;i--)
	{
		cout<<a[i];
	}
	return 0;
}
