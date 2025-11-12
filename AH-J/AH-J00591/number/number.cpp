#include <bits/stdc++.h>
using namespace std;
long long t,f[20],sum;
char s[1000010];
int main()
{
	freopen("number4.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(long long i=0; i<(long long)strlen(s); i++)
	{
		if(s[i]>='1' && s[i]<='9') f[s[i]-'0']++;
		else if(s[i]=='0') sum++;
	}
	for(long long i=9; i>0; i--) if(f[i])
	{
		for(long long j=1; j<=f[i]; j++) cout<<i;
	}
	for(long long i=1; i<=sum; i++) cout<<0;
	return 0;
}