#include <bits/stdc++.h>
using namespace std;
int read()
{
	int x=0;
	bool neg=false;
	char c=getchar_unlocked();
	while(c<'0')
	{
		if(c=='-') neg=true;
		c=getchar_unlocked();
	}
	while(c>='0')
	{
		x=x*10+c-'0';
		c=getchar_unlocked();
	}
	if(neg) return -x;
	return x;
}
void write(int x)
{
	if(x<0)
	{
		putchar_unlocked('-');
		write(-x);
		return;
	}
	if(x<=9)
	{
		putchar_unlocked(x+'0');
		return;
	}
	write(x/10);
	putchar_unlocked(x%10+'0');
}
int a[100012],b[100012],c[100012];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--)
	{
		int n=read(),qa=0,qb=0,qc=0,s=0;
		for(int i=1;i<=n;i++)
		{
			a[i]=3*read()+2;
			b[i]=3*read()+1;
			c[i]=3*read()+0;
			if(a[i]>b[i]&&a[i]>c[i])
			{
				qa++;
				s+=a[i]/3;
			}
			if(b[i]>a[i]&&b[i]>c[i])
			{
				qb++;
				s+=b[i]/3;
			}
			if(c[i]>a[i]&&c[i]>b[i])
			{
				qc++;
				s+=c[i]/3;
			}
		}
		if(qa<=n/2&&qb<=n/2&&qc<=n/2)
		{
			write(s);
			putchar_unlocked('\n');
			continue;
		}
		if(qa>n/2)
		{
			priority_queue<int,vector<int>,greater<int> > pq;
			for(int i=1;i<=n;i++)
				if(a[i]>b[i]&&a[i]>c[i]) pq.push(a[i]/3-max(b[i]/3,c[i]/3));
			for(int i=1;i<=qa-n/2;i++)
			{
				s-=pq.top();
				pq.pop();
			}
			write(s);
			putchar_unlocked('\n');
			continue;
		}
		if(qb>n/2)
		{
			priority_queue<int,vector<int>,greater<int> > pq;
			for(int i=1;i<=n;i++)
				if(b[i]>a[i]&&b[i]>c[i]) pq.push(b[i]/3-max(a[i]/3,c[i]/3));
			for(int i=1;i<=qb-n/2;i++)
			{
				s-=pq.top();
				pq.pop();
			}
			write(s);
			putchar_unlocked('\n');
			continue;
		}
		if(qc>n/2)
		{
			priority_queue<int,vector<int>,greater<int> > pq;
			for(int i=1;i<=n;i++)
				if(c[i]>a[i]&&c[i]>b[i]) pq.push(c[i]/3-max(a[i]/3,b[i]/3));
			for(int i=1;i<=qc-n/2;i++)
			{
				s-=pq.top();
				pq.pop();
			}
			write(s);
			putchar_unlocked('\n');
			continue;
		}
	}
	return 0;
}
// 14:30 - 14:45, samples passed (48 ms), 100 / 100 points
