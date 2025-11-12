#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long a=0,sum=0,number_sum=0;
	int b[100000];
	a=s.length();
	for(int i=0;i<=a;i++)
	{
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9')
		{
			b[i]=s[i]-'0';
			number_sum++;
		}
	}
	for(int j=0;j<=number_sum;j++)
	{
		for(int k=0;k<=number_sum-j-1;k++)
		{
			if(b[k]>b[k+1])
			{
				swap(b[k],b[k+1]);
			}
		}
	} 
	sum+=b[1];
	int c=1;
	for(int l=1;l<=number_sum;l++)
	{
		c=c*10;
		sum+=c*b[l+1];
	}
	cout<<sum;
	return 0;
 } 
