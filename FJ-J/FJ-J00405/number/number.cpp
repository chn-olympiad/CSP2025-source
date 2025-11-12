#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
long long maxx=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	getline(cin,s);
	long long ans=1,f;
	for(long long i=0;i<=s.size();i++)
	{
		if(s[i]>=48&&s[i]<=57)  
		{
			a[ans]=s[i]-48;
			ans++;
		}
	}
	ans--;
	sort(a+1,a+1+ans);
	long long sz=0,sw=1;
	for(long long i=1;i<=ans;i++)
	{
		sz+=sw*a[i];
		sw*=10;
	}
	cout<<sz;
	return 0;
}
