#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read()
{
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		f=(ch=='-'?-1:f);
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
void write(ll x)
{
	if(x<0)
	{
		putchar('-');
		write(-x);
		return ;
	}
	if(x>9)write(x/10);
	putchar(x%10+48);
}
void writech(ll x,char ch)
{
	write(x);
	putchar(ch);
}
const int MAXN=1e5+10;
int a[3][MAXN],cho[MAXN],chan[MAXN],tot;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--)
	{
		int n=read();
		ll sum=0;
		int cnt0=0,cnt1=0,cnt2=0;
		for(int i=1;i<=n;i++)
		{
			a[0][i]=read();
			a[1][i]=read();
			a[2][i]=read();
			if(a[0][i]>a[1][i]&&a[0][i]>a[2][i])
			{
				cho[i]=0;
				cnt0++;
				sum+=a[0][i];
			}
			else if(a[1][i]>a[2][i])
			{
				cho[i]=1;
				cnt1++;
				sum+=a[1][i];
			}
			else
			{
				cho[i]=2;
				cnt2++;
				sum+=a[2][i];
			}
		}
		tot=0;
		if(cnt0>n/2)
		{
			for(int i=1;i<=n;i++)
			{
				if(cho[i]==0)
				{
					chan[++tot]=a[0][i]-max(a[1][i],a[2][i]);
				}
			}
			sort(chan+1,chan+tot+1);
			for(int i=1;i<=cnt0-n/2;i++)
			{
				sum-=chan[i];
			}
		}
		else if(cnt1>n/2)
		{
			for(int i=1;i<=n;i++)
			{
				if(cho[i]==1)
				{
					chan[++tot]=a[1][i]-max(a[0][i],a[2][i]);
				}
			}
			sort(chan+1,chan+tot+1);
			for(int i=1;i<=cnt1-n/2;i++)
			{
				sum-=chan[i];
			}
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				if(cho[i]==2)
				{
					chan[++tot]=a[2][i]-max(a[1][i],a[0][i]);
				}
			}
			sort(chan+1,chan+tot+1);
			for(int i=1;i<=cnt2-n/2;i++)
			{
				sum-=chan[i];
			}
		}
		writech(sum,'\n');
	}
	return 0;
}
