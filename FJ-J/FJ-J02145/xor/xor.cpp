#include<bits/stdc++.h>
using namespace std;
unsigned long long n,k;
unsigned long long a[500010];
struct node 
{
	unsigned long long aa,bb;
}e[50000010];
bool cmp(node o,node p)
{
	if(o.bb-o.aa==p.bb-p.aa)
		return o.aa<p.aa;
	return o.bb-o.aa<p.bb-p.aa;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	unsigned long long tmp=1,cnt=1,sum=0;
	for(unsigned long long i=1;i<=n;i++)
	for(unsigned long long j=i;j<=n;j++)
	{
		if(j==i)
		{
			tmp=a[j];
		}
		else
		{
			tmp=(unsigned long long)(tmp^a[j]);
		}
		if(tmp==k)
		{
			e[cnt].aa=i;
			e[cnt].bb=j;
			cnt++;
		}
		if(j==n)
		{
			tmp=0;
		}
	}
	sort(e+1,e+cnt,cmp);
	/*for(int i=1;i<cnt;i++)
	{
		cout<<e[i].aa<<" "<<e[i].bb<<endl;
	}*/
	for(unsigned long long i=1;i<cnt;i++)
	{
		unsigned long long x,y;
		x=e[i].aa;
		y=e[i].bb;
		bool flag=true;
		for(int j=x;j<=y;j++)
		{
			if(a[j]==-1)
				flag=false;
		}
		if(flag==true)
		{
			sum++;
			for(int j=x;j<=y;j++)
			{
				a[j]=-1;
			}
		}
	}
	cout<<sum;
	return 0;
}
