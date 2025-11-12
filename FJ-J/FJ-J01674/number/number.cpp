#include<bits/stdc++.h>
using namespace std;
long long x[100001],k=1;
bool cmp(long long a,long long b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long len=s.size();
	for(long long i=0;i<len;i++)
	{
		if('0'<=s[i]&&s[i]<='9')
		{
			x[k]=s[i]-'0';
			k++;
		}
	}
	sort(x+1,x+k+1,cmp);
	for(long long i=1;i<k;i++)
	cout<<x[i];
	return 0;
}
