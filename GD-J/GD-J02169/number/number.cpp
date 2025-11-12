#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000005],l,n;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	l=s.size();
	for(long long i=0;i<l;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[++n]=(long long)(s[i]-'0');
		}
	}
	sort(a+1,a+n+1,greater<int>());
	for(long long i=1;i<=n;i++)
	{
		cout<<a[i];
	}
	return 0;
}
