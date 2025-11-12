#include<bits/stdc++.h>
using namespace std;
char a[114514];
int sum[114514],ans[114514];
long long n=0,m;
long long string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		a[i]=s[i];
	}
	for(int i=0;i<s.size();i++)
	{
		if(a[i]-'0'>=0&&a[i]-'0'<=9)
		{
			n++;
			sum[n]=a[i]-'0';
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(sum[i]>=sum[j]&&sum[i]>=m)
			{
				m=sum[i];
			}
			else if(sum[i]<sum[j]&&sum[j]>=m)
			{
				m=sum[j];
			}
		}
		ans[i]=m;
		for(int k=1;k<=n+1;k++)
		{
			if(sum[k]==m)
			{
				sum[k]=-1;
				break;
			}
		}
		m=0;
	}
	for(int i=1;i<=n;i++)
	{
		cout<<ans[i];
	}
	return 0;
}
