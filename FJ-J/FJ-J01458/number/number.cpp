#include <bits/stdc++.h>
using namespace std;
long long a[1000010];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long n=s.size();
	long long cnt=0;
	for(long long i=0;i<n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[cnt]=s[i]-'0';
			cnt++;
		}
	}
	sort(a,a+cnt);
	for(long long i=cnt-1;i>=0;i--)
	{
		cout<<a[i];
	}
	return 0;
 } 
