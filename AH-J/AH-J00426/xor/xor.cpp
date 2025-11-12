#include<bits/stdc++.h>
using namespace std;
long long a[500200],sum,n,k,ew=0;
bool q=1;
int yihuo(int aa,int bb)
{
	long long w=0,q1=0,q2=0,q;
	int a11[2650]={},b11[2650]={},c[2650]={};
	while(aa!=0)
	{
		q1++;
		a11[q1]=aa%2;
		aa/=2;
		}
	while(bb!=0)
	{
		q2++;
		b11[q2]=bb%2;
		bb/=2;
	}
	q=max(q1,q2);
	for(int i=1;i<=q;i++)
	{	
		if(b11[i]==a11[i])c[i]=0;
		else c[i]=1;
	}
	for(int i=1;i<=q;i++)
	{
		long long a=1;
		for(int j=2;j<=i;j++)
		{
			a*=2;
		}
		w+=c[i]*a;
	}
	return w;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		}
	for(long long i=1;i<=n;i++)
	{
		if(a[i]==k)
		{
			sum++;
			continue;
		}
		ew=a[i];
		for(int j=i+1;j<=n;j++)
		{
			ew=yihuo(ew,a[j]);
			if(ew==k)
			{
				sum++;
				i=j;
				break;
			}
			}
	}
	cout<<sum;
}
	
	

