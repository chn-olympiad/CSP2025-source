#include<bits/stdc++.h>
using namespace std;
int a[500005]={0},n,k,b[500005],ac;
int xr(int oc,int oo)
{
	int ocl[100]={0},ool[100]={0},otl[100],ot=0;
	for(int i=20;i>=0;i--)
	{
		if(oc<pow(2,i) and oo<pow(2,i))
			continue;
		if(oc>=pow(2,i))
		{
			oc-=pow(2,i);
			ocl[i]=1;
		}
		if(oo>=pow(2,i))
		{
			oo-=pow(2,i);
			ool[i]=1;
		}
	}
	for(int i=20;i>=0;i--)
	{
		otl[i]=1;
		if(ool[i]==ocl[i])
			otl[i]=0;
	}
	for(int i=20;i>=0;i--)
	{
		ot+=pow(2,i)*otl[i];
	}
	return ot;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			ac=xr(ac,b[j]);
			if(j==i)
				ac=b[j];
			if(ac==k)
			{
				a[i]=j;
				break;
			}
		}
	}
	int ml=500005;
	for(int i=n-1;i>=1;i--)
	{
		if(a[i]>=ml)
			a[i]=0;
		else if(a[i]!=0)
		{
			ml=a[i];
		}
	}
	int q=0,e=1;
	while(e<=n)
	{
		if(a[e]!=0)
		{
			e=a[e]+1;
			q++;
		}
		else
		{
			e++;
		}
	}
	cout<<q;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
