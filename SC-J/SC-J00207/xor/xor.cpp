#include<bits/stdc++.h>
using namespace std;
int n,k,a[500050],ii=1,f[500050],br=1e8,bl,sum;
void q(int s,int m,int r,int l)
{
	if(m>k||s==n+1) return;
	if(s==-1)
	{
		if(m==k)
		{
			if(bl<r||br>l)
			{
				sum++;
				bl=l;
				br=r;
			}
		}
		return;
	}
	q(-1,a[s],s,s);
	f[s]=a[s];
	for(int i=s+1;i<=n;i++)
	{
		f[i]=f[i-1]^a[i];
		q(-1,f[i],s,i);
	}
	q(s+1,0,0,0);
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	q(1,0,0,0);
	printf("%d",sum);
	return 0; 
}
