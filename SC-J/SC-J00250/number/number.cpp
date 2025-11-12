#include<bits/stdc++.h>
using namespace std; 
string s;
long long a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long n=s.size();
	long long cnt=0;
	for(long long i=0;i<n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[++cnt]=s[i]-'0';
		}
	}
	sort(a+1,a+1+cnt);
	for(long long i=cnt;i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
}