#include<bits/stdc++.h>
using namespace std;
string a;
int b[1000000],n=0,x;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>a;
	for(int i=0;i<a.length();i++)
	{
		if(a[i]>='0' && a[i]<='9')
		{
			b[n]=a[i]-'0';
			n++;
		}
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(b[i]>b[j])
			{
				x=b[i];
				b[i]=b[j];
				b[j]=x;
			}
		}
	}
	
	for(int i=0;i<n;i++)
	{
		cout<<b[i];
	}
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
