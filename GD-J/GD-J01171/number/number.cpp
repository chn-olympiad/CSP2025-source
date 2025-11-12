#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long n=s.size(),t=0;
	for(int i=0; i<n; i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			a[++t]=s[i]-'0';
		}
	}
	sort(a+1,a+1+t);
	if(a[t]==0) 
	{
		printf("0\n");
		return 0;
	}
	for(int i=t; i>=1; i--)
	{
		printf("%d",a[i]);
	}
	printf("\n");
	return 0;
 } 
