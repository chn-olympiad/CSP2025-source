#include<bits/stdc++.h>
using namespace std;
long long a[500000+5],k,n,m,t,p,e,q;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	if(n>=3)
	for(int i=1;i<=n-2;i++)
	for(int j=i+1;j<=n-1;j++)
	for(int l=j+1;l<=n;l++)
	{
		p=max(a[i],a[j]);
		p=max(p,a[l]);
		q=a[i]+a[j]+a[l];
		if(q>p*2)
		t++;
	}
	if(n>=4)
	for(int i=1;i<=n-3;i++)
	for(int j=i+1;j<=n-2;j++)
	for(int l=j+1;l<=n-1;l++)
	for(int o=l+1;o<=n;o++)
	{
		p=max(a[i],a[j]);
		e=max(a[o],a[l]);
		p=max(p,e);
		q=a[i]+a[j]+a[l]+a[o];
		if(q>p*2)
		t++;
	}
	if(n>=5)
	for(int i=1;i<=n-4;i++)
	for(int j=i+1;j<=n-3;j++)
	for(int l=j+1;l<=n-2;l++)
	for(int o=l+1;o<=n-1;o++)
	for(int x=o+1;x<=n;x++)
	{
		p=max(a[i],a[j]);
		e=max(a[o],a[l]);
		p=max(p,e);
		p=max(p,a[x]);
		q=a[i]+a[j]+a[l]+a[o]+a[x];
		if(q>p*2)
		t++;	
	}					
	if(n>=6)
	for(int i=1;i<=n-5;i++)
	for(int j=i+1;j<=n-4;j++)
	for(int l=j+1;l<=n-3;l++)
	for(int o=l+1;o<=n-2;o++)
	for(int x=o+1;x<=n-1;x++)
	for(int y=x+1;y<=n;y++)
	{
		p=max(a[i],a[j]);
		e=max(a[o],a[l]);
		p=max(p,e);
		p=max(p,a[x]);
		p=max(p,a[y]);
		q=a[i]+a[j]+a[l]+a[o]+a[x]+a[y];
		if(q>p*2)
		t++;	
	}
	if(n>=7)
	for(int i=1;i<=n-6;i++)
	for(int j=i+1;j<=n-5;j++)
	for(int l=j+1;l<=n-4;l++)
	for(int o=l+1;o<=n-3;o++)
	for(int x=o+1;x<=n-2;x++)
	for(int y=x+1;y<=n-1;y++)
	for(int z=y+1;z<=n;z++)
	{
		p=max(a[i],a[j]);
		e=max(a[o],a[l]);
		p=max(p,e);
		p=max(p,a[x]);
		p=max(p,a[y]);
		p=max(p,a[z]);
		q=a[i]+a[j]+a[l]+a[o]+a[x]+a[y]+a[z];
		if(q>p*2)
		t++;
	}
	if(n>=8)
	for(int i=1;i<=n-7;i++)
	for(int j=i+1;j<=n-6;j++)
	for(int l=j+1;l<=n-5;l++)
	for(int o=l+1;o<=n-4;o++)
	for(int x=o+1;x<=n-3;x++)
	for(int y=x+1;y<=n-2;y++)
	for(int z=y+1;z<=n-1;z++)
	for(int h=z+1;h<=n;h++)
	{
		p=max(a[i],a[j]);
		e=max(a[o],a[l]);
		p=max(p,e);
		p=max(p,a[x]);
		p=max(p,a[y]);
		p=max(p,a[z]);
		p=max(p,a[h]);
		q=a[i]+a[j]+a[l]+a[o]+a[x]+a[y]+a[z]+a[h];
		if(q>p*2)
		t++;
	}
	if(n>=9)
	for(int i=1;i<=n-8;i++)
	for(int j=i+1;j<=n-7;j++)
	for(int l=j+1;l<=n-6;l++)
	for(int o=l+1;o<=n-5;o++)
	for(int x=o+1;x<=n-4;x++)
	for(int y=x+1;y<=n-3;y++)
	for(int z=y+1;z<=n-2;z++)
	for(int h=z+1;h<=n-1;h++)
	for(int u=h+1;u<=n;u++)
	{
		p=max(a[i],a[j]);
		e=max(a[o],a[l]);
		p=max(p,e);
		p=max(p,a[x]);
		p=max(p,a[y]);
		p=max(p,a[z]);
		p=max(p,a[h]);
		p=max(p,a[u]);
		q=a[i]+a[j]+a[l]+a[o]+a[x]+a[y]+a[z]+a[h]+a[u];
		if(q>p*2)
		t++;
	}
	if(n>=10)
	for(int i=1;i<=n-9;i++)
	for(int j=i+1;j<=n-8;j++)
	for(int l=j+1;l<=n-7;l++)
	for(int o=l+1;o<=n-6;o++)
	for(int x=o+1;x<=n-5;x++)
	for(int y=x+1;y<=n-4;y++)
	for(int z=y+1;z<=n-3;z++)
	for(int h=z+1;h<=n-2;h++)
	for(int u=h+1;u<=n-1;u++)
	for(int k=u+1;k<=n;k++)
	{
		p=max(a[i],a[j]);
		e=max(a[o],a[l]);
		p=max(p,e);
		p=max(p,a[x]);
		p=max(p,a[y]);
		p=max(p,a[z]);
		p=max(p,a[h]);
		p=max(p,a[u]);
		p=max(p,a[k]);
		q=a[i]+a[j]+a[l]+a[o]+a[x]+a[y]+a[z]+a[h]+a[u]+a[k];
		if(q>p*2)
		t++;
	}
	cout<<t;
	return 0;
}
