#include<bits/stdc++.h>
using namespace std;
char a[1000001];
int i=1,j,k,l,m,ans,anstong[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	do
	{
		cin>>a[i];
		i++;
	}while(a[i-1]==' ');
	if(i-1==1)
	{
	    cout<<a[i-1];
	    return 0;
	}
	for(j=1;j<=i;j++)
	{
		if(int(a[i])>=int('0')&&int(a[i])<=int('9'))
		{
		    ans=int(a[i])-int('0');
		    anstong[ans]++;
		}
	}
	for(l=9;l>=0;l--)
	{
		for(m=1;m<=anstong[l];m++)
		cout<<l;
	}
	return 0;
 } 
