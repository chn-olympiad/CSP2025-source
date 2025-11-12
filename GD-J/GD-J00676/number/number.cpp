#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char a[1000003],b[100001];
	cin>>a;
	int s=0;
	for(int i=0;i<strlen(a);i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			b[s]=a[i];
			s+=1;
		}
	}
	for(int i=0;i<s;i++)
	{
		for(int j=0;j<s-i;j++)
		{
			if(b[j]>b[j+1])
			{
				swap(b[j+1],b[j]);
			}
		}
	}
	for(int i=s;i>0;i--)
	{
		cout<<b[i];
	}
 } 
