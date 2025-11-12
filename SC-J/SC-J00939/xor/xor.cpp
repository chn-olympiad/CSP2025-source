#include<bits/stdc++.h>
using namespace std;
int n,k,a[1100],cnt,f[1100],p=1;
struct node
{
	int ll,rr;
}b[100010];
bool sum(node a,node b)
{
	return a.rr<b.rr; 
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)	cin>>a[i];
	for(int l=1;l<=n;l++)
	{
		int x=a[l];
		if(x==k)
		{
			b[++cnt].ll=l;
			b[cnt].rr=l;
		}
		for(int r=l+1;r<=n;r++)
		{
			x=x xor a[r];
			if(x==k)
			{
				b[++cnt].ll=l;
				b[cnt].rr=r;
			}
		}
	}
	sort(b+1,b+1+cnt,sum);
	for(int i=1;i<=n;i++)
	{
		while(b[p].rr==i)
		{
			f[i]=max(f[i],f[b[p].ll-1]+1);
			p++;
		}
		f[i]=max(f[i],f[i-1]);
	}
	cout<<f[n];
	return 0;
}