#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w".stdout);
	int a[101],n,s=0,v=0,c=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=3;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			for(int x=1;x<=j;x++)
			{
				if(a[j]+a[i]+a[x]>2*v) c++;
			}
			if(a[j]>=s) s=a[j];
			v+=a[j];
		}
		s=0;
		v=0;
	}
	cout<<c<<endl;
	return 0;
}
