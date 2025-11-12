#include<bits/stdc++.h>
using namespace std;
string s;
long long a[99];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if('0'<=s[i]&&s[i]<='9')
		    a[int(s[i]-'0')]++;
	}
	for(int i=9;i>=0;i--)
	{
		if(a[i]>=1)
			for(int j=1;j<=a[i];j++)
			    printf("%lld",i);
	}

	return 0;
}
