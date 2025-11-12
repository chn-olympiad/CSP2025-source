#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

inline int read()
{
	int x=0,fu=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')fu=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*fu;
}

void write(int x)
{
	if(x<0){putchar('-'),x=-x;}
	if(x<10){putchar(x+'0');return;}
	write(x/10);putchar(x%10+'0');
}

priority_queue<int,vector<int>,greater<int> >q[3];
int n,ans;
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--)
	{
		ans=0;
		for(int i=0;i<=2;i++)
			while(!q[i].empty())	q[i].pop();
		
		n=read();
		int tot0=0,tot1=0,tot2=0;
		for(int i=1;i<=n;i++)
		{
			int x=read(),y=read(),z=read();
			if(x>=y&&x>=z)
			{
				ans+=x;
				tot0++;
				q[0].push(x-max(y,z));
			}
			else if(y>=x&&y>=z)
			{
				ans+=y;
				tot1++;
				q[1].push(y-max(x,z));
			}
			else
			{
				ans+=z;
				tot2++;
				q[2].push(z-max(x,y));
			}
		}
		if(tot0>n/2)
		{
			for(int i=n/2+1;i<=tot0;i++)	ans-=q[0].top(),q[0].pop();
		}
		if(tot1>n/2)
		{
			for(int i=n/2+1;i<=tot1;i++)	ans-=q[1].top(),q[1].pop();
		}
		if(tot2>n/2)
		{
			for(int i=n/2+1;i<=tot2;i++)	ans-=q[2].top(),q[2].pop();
		}
		write(ans),puts("");
	}
	return 0;
}