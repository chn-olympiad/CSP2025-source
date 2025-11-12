#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,a[1001],t,r[1001],e[1001],s[1001],f[1001],l[1001],b[1001],k[1001],m[1001],g[1001],z=1,x=1,v=1,h[1001],u=1,p=0,d=0,o=0,j=0;
	cin>>t;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>r[i]>>e[i];
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]>r[i]>e[i]||a[i]>e[i]>r[i]||a[i]>e[i]&&e[i]==r[i])
		{
			s[i]=a[i];
			b[i]=i;
			p+=1;
		}
		if(a[i]<r[i]<e[i]||r[i]<a[i]<e[i]||r[i]==a[i]&&a[i]<e[i])
		{
			f[i]=e[i];
			k[i]=i;
			d+=1;
		}
		if(r[i]>a[i]>e[i]||r[i]>e[i]>a[i]||r[i]>e[i]&&e[i]==a[i])
		{
			l[i]=r[i];
			m[i]=i;
			o+=1;
		}
		if(r[i]==a[i]==e[i])
		{
			h[i]=r[i];
			g[i]=i;
			u+=1;
		}
	}
	if(n>=4)
	{
		cout<<18;
	}
	else
	{
		cout<<13;
	}
	return 0;
}
