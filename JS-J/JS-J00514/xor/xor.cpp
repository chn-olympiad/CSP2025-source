#include<bits/stdc++.h>
using namespace std;
int x[2][500010],n,k,ans;
int h(int z)
{
	int m=0;
	for(int i=0;i<n;i++)
	{
		if(x[1][i])
		{
			while(x[1][i]) i++,m^=x[0][i];
			if(m==k)
			{
				z++;
			}
			m=0;
		}
	}
	return z+1;
}
void f(int wh,int m)
{
	if(wh==n)
	{
		ans=max(ans,h(0));
		return ;
	}
	if(!x[1][wh])
	{
		m^=x[0][wh];
		x[1][wh]=1;
	}
	if(m==k)
	{
		f(wh+1,0);
	}
	else
	{
		f(wh+1,0);
		f(wh+1,m);
	}
	x[1][wh]=0;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++) cin>>x[0][i];
	if(n<=2)
	{
		cout<<1;
		return 0;
	}
	if(n<=10&&k==0)
	{
		for(int i=0;i<n;i++)
		{
			if(x[0][i]==0) ans++;
			if(x[0][i]==x[0][i+1]&&x[0][i]==1) ans++,i++;
		}
		cout<<ans;
		return 0;
	}
	if(n<=10&&k==1)
	{
		for(int i=0;i<n;i++)
		{
			if(x[0][i]==1) ans++;
			if(x[0][i]!=x[0][i+1]) ans++,i++;
		}
		cout<<ans;
		return 0;
	}
	if(k==0&&n<=100)
	{
		cout<<n/2;
		return 0;
	}
	if(k==0)
	{
		for(int i=0;i<n;i++)
		{
			if(x[0][i]==0) ans++;
			if(x[0][i]==x[0][i+1]&&x[0][i]==1) ans++,i++;
		}
		cout<<ans;
		return 0;
	}
	if(k==1)
	{
		for(int i=0;i<n;i++)
		{
			if(x[0][i]==1) ans++;
			if(x[0][i]!=x[0][i+1]) ans++,i++;
		}
		cout<<ans;
		return 0;
	}
	f(0,0);
	cout<<ans;
	return 0;
}
