#include<bits/stdc++.h>
using namespace std;
long long a[100100],b[100100],c[100100],m,n,ansa;
void dfs(int numa,int numb,int numc,int ad,int k)
{
	if(k>n)
	{
		if(ad>ansa) ansa=ad;
		return;
	}
	if(numa<m) dfs(numa+1,numb,numc,ad+a[k],k+1);
	if(numb<m) dfs(numa,numb+1,numc,ad+b[k],k+1);
	if(numc<m) dfs(numa,numb,numc+1,ad+c[k],k+1);
	return;
}
void dfs2(int numa,int numb,int ad,int k)
{
	if(k>n)
	{
		if(ad>ansa) ansa=ad;
		return;
	}
	if(numa<m) dfs2(numa+1,numb,ad+a[k],k+1);
	if(numb<m) dfs2(numa,numb+1,ad+b[k],k+1);
	return;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long T,i;
	scanf("%lld",&T);
	while(T--)
	{
		int pdb=0,pdc=0,pda=0;
		ansa=0;
		scanf("%lld",&n);
		for(i=1;i<=n;++i)
		{
			scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
			if(a[i]!=0) pda=1;
			if(b[i]!=0) pdb=1;
			if(c[i]!=0) pdc=1;
		}
		if(pdb==0&&pdc==0)
		{
			sort(a+1,a+n+1);
			for(i=n;i>n/2;--i) ansa+=a[i];
			cout<<ansa<<endl;
		}
		else if(pda==0&&pdc==0)
		{
			sort(b+1,b+n+1);
			for(i=n;i>n/2;--i) ansa+=b[i];
			cout<<ansa<<endl;
		}
		else if(pda==0&&pdb==0)
		{
			sort(c+1,c+n+1);
			for(i=n;i>n/2;--i) ansa+=c[i];
			cout<<ansa<<endl;
		}
		else if(pdc==0)
		{
			m=n/2;
			dfs2(0,0,0,1);
			cout<<ansa<<endl;
		}
		else
		{
			m=n/2;
			dfs(0,0,0,0,1);
			cout<<ansa<<endl;
		}
	}
	return 0;
}
