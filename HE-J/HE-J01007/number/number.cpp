#include<iostream>
using namespace std;
int sum[10000];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","d",stdout);
	string s;
	cin>>s;
	int n=1;
	for(int i=1;i<=sizeof(s)+1;i++)
	{
		if(s[i]<='9')
		{
			if(s[i]>='0')
			{
				sum[n]=s[i]-'0';
				n++;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(sum[j]<sum[j+1])
			{
				int t=sum[j];
				sum[j]=sum[j-1];
				sum[j+1]=t; 
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<sum[i];
	}
 } 
