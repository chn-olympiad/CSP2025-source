#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005],f[500005],b[2000002],ans,h;
int yihuo(int x,int y)
{
	int ans=0,t=0;
	while(x>0||y>0)
	{
		int r=x%2,l=y%2;
		if(r!=l)
		{
			ans+=(1<<t);
		}
		x>>=1;
		y>>=1;
		t++;
	}
	return ans;
}
int fantui(int y,int x)
{
	int ans=0,t=0;
	while(y>0||x>0)
	{
		if(y%2==1)
		{
			ans+=((x%2+1)%2)<<t;
		}
		else
		{
			ans+=(x%2)<<t;
		}
		y>>=1;
		x>>=1;
		t++;
	}
	return ans;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++,h++)
	{
		cin>>a[i];
		if(a[i]==0&&k!=0)
		{
			continue;
		}
		if(h==0)
		{
			f[i]=a[i];
		}
		else
		{
			f[i]=yihuo(f[i-1],a[i]);
		}
		int y=b[f[i]];
		b[f[i]]=i;
		if(f[i]==k||a[i]==k)
		{
			ans++;
			h=-1;
		}
		else if(b[fantui(f[i],k)]>=i-h)
		{
			if(h==0)
			{
				continue;
			}
			ans++;
			h=-1;
		}
	}
	cout<<ans;
	return 0;
}
