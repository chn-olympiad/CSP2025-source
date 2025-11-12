#include<bits/stdc++.h>
using namespace std;
char s[1000001];
int num[1000001];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long cnt=0;
	cin>>s;
	for(long unsigned int i=0;i<=strlen(s);i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			num[cnt]=int(s[i]);
			cnt++;
		}
	}
	long unsigned int c;
	int min=200;
	for(long long i=0;i<cnt;i++)
	{
		if(num[i]<=min)
		{
			min=num[i];
			c=i;
		}
	}
	num[c]=201;
	int nu[cnt];
	for(long long i=0;i<cnt;i++)
	{
		nu[cnt-(i+1)]=min;
		min=200;
		for(long long j=0;j<cnt;j++)
		{
			if(min>=num[j]&&num[j]>=nu[cnt-i-1])
			{
				min=num[j];
				c=j;
			}
		}
		num[c]=201;
	}
	for(long long i=0;i<cnt;i++)
	{
		cout<<nu[i]-48;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
