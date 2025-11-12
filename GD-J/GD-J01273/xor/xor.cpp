#include<bits/stdc++.h>
using namespace std;
int q=(1<<20);
int n,k,a[500005],f[500005],bz[(1<<20)+5],maxf[500005],v,p;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	f[0]=0;
	maxf[0]=0;
	for(int i=0;i<=q;i++)
		bz[i]=2100000000;
	v=0;
	bz[v]=0;
	for(int i=1;i<=n;i++)
	{
		v^=a[i];
		p=bz[k^v];
		if(p!=2100000000)
		{
			f[i]=maxf[p]+1;
		}
		maxf[i]=max(maxf[i-1],f[i]);
		bz[v]=i;
	}
	cout<<maxf[n];
}
