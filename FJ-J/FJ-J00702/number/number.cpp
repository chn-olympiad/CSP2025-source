#include<bits/stdc++.h>
using namespace std;
char a[1000001];
long long int b[10]={0};
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<strlen(a);i++)
	{
		if(a[i]-'0'>=0&&a[i]-'0'<=9)
		{
			b[a[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		if(b[i]>0)
		{
			for(int j=0;j<b[i];j++)
			{
				cout<<i;
			}
		}
	}
	return 0;
} 
