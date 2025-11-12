#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,x,max,m=0,p=0;
	cin>>n;
	int a[n+1],s[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=3;i<=n;i++)
	{
		for(int y=n;y>=i;y--)
		{
			x=i;
			for(int j=1;j<=i;j++)
			{
				s[j]=a[j];
			}
			while(x>0)
			{
				for(int j=x;j<=y-i+x;j++)
				{
					s[x]=a[j];
					max=s[1];
					for(int k=1;k<=i;k++)
					{
						m+=s[k];
						if(s[k]>max)max=s[k];
					}
					if(m>2*max)p++;
					m=0;
				}
				x--;
			}
		}
	}
	cout<<((p%998)%244)%353;
	return 0;
}
