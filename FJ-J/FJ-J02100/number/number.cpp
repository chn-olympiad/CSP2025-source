#include <bits/stdc++.h>
using namespace std;
string a,f;
int j,x,sum[1000005];
int hs(int b,int c)
{
	return b>c;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	a=" "+a;
	for(int i=1;i<=a.length();i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			j++;
			x=a[i];
			f[j]=x;
			
			sum[j]=f[j];
		}
	}
	sort(sum+1,sum+j+1,hs);
	for(int i=0;i<j;i++)
	{
		f[i]=sum[i];
		cout<<f[i];
	}
	return 0;
}
