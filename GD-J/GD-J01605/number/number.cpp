#include<bits/stdc++.h>
using namespace std;
string s;
long long a[100010],I=0,p[100010];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long i;
	for(i=0;i<s.size();i++)if(s[i]>='0'&&s[i]<='9')a[++I]=int(s[i])-48;
	for(i=1;i<=I;i++)p[a[i]]++;
	for(i=9;i>=0;i--)if(p[i]!=0)for(long long j=1;j<=p[i];j++)cout<<i;
	return 0;
} 
