#include <bits/stdc++.h>
using namespace std;

string s;
long long a[10000000];
long long lena=1;


int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long len=s.size();
	
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			a[lena]=s[i]-'0';
			lena++;
		}
	}
	
	sort(a+1,a+lena);
	
	for(int i=lena-1;i>=1;i--)
	{
		cout<<a[i];
	}
	
	return 0;
} 
