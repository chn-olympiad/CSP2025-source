#include <bits/stdc++.h>
using namespace std;
string s;
char ll;
short a[1000005],p=-1;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		ll=s[i];
		if(ll>'z'||ll<'a')
		{
			p++;
			a[p]=ll-48;
		}
	}
	sort(a,a+p+1);
	for(int i=p;i>=0;i--)
	{
		cout<<a[i];
	}
	
}

