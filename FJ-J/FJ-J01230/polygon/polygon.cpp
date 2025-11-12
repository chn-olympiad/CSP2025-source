#include<bits/stdc++.h>
using namespace std;
long long n,a[52601],t,l,ans,o,p;
void cz(long long x,long long y,long long w,long long ma)
{
	if(y>=3&&w>ma*2)
	{
		ans++;
		ans%=998244353;
	}
	for(int i=x+1;i<=n;i++)
	{
		cz(i,y+1,w+a[i],max(ma,a[i]));
	}
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<=25)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		} 
		cz(0,0,0,0);
		cout<<ans;
		return 0;
	}
	else
	{	
		for(int i=1;i<=n;i++)
		{
			cin>>l; 
			a[l]+=1;
			t=max(l,t);
		}
		if(t==1)
		{
			for(int i=3;i<=n;i++)
			{
				o=1;
				p=1;
				for(int j=n-i+1;j<=n;j++)
				{
					p*=j;
					if(p%o==0&&o<=i)
					{
						p/=o;
						o++;
					}
					p%=998244353;
				}
				ans+=p;
				ans%=998244353;
			}
		}
		cout<<ans;
	}
}





























