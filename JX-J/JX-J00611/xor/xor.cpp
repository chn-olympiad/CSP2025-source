#include<bits/stdc++.h>
using namespace std;
int n,k,a[100001],l[100001],r[100001],l1,r1;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int sdm=0,e=0;
	cin>>n>>k;
	l[sdm]=1;
	l[sdm]=n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int sum=a[i],j=i+1,ey=0;
		if(sum!=k)
		{
			while(sum!=k&&j<=n)
			{
				sum=sum^a[j];
				j++;	
				if(sum==k)
				{
					ey=1;
					e=1;

				}
			}
		}
		else
		{
			ey=1;
			e=1;
		}
		l1=i;
		r1=--j;
		if(ey==1&&l1>=l[sdm]&&r1<r[sdm])
		{
			l[sdm]=l1;
			r[sdm]=r1;
		}
		if(ey==1&&l1>r[sdm])
		{
			l[++sdm]=l1;
			r[sdm]=r1;
		}
	}
	if(e==1)
		cout<<sdm;
	else
		cout<<sdm;
}
