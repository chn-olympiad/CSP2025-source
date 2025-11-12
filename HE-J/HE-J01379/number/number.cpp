#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000005];
long long shu=1;
long long maxx=0;
long long n=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[shu]=(s[i]-'0');
			n++;
			shu++;
		}
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
}
