#include<bits/stdc++.h>
using namespace std;
#define maxn 100001
int t,n,ans;
int a[maxn][4],d[maxn];
int in()
{
	char k=getchar();
	int kk=0,f=1;
	while(k<'0'&&k>'9')
	{
		if(k=='-')f=-1;
		k=getchar();
	}
	while(k>='0'&&k<='9')kk=kk*10+k-'0',k=getchar();
	return f*kk;
}
void out(int x)
{
	if(x<0)putchar('-'),x=-x;
	if(x<10)putchar(x+'0');
	else out(x/10),putchar(x%10+'0');
	return ;
}
void work(int p,int q)
{
	int dd[maxn],cnt=p-(n/2);
	for(int i=1;i<=n;i++)dd[i]=a[i][q];
	sort(dd+1,dd+n+1);
	for(int j=1;j<=cnt;)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i][q]==dd[j])a[i][q]=-1,j++;
			if(j>cnt)i=n+1;
		}
	}
	return ;
}
void f()
{
	int x=0,y=0,z=0;
	for(int i=1;i<=n;i++)
	{
		int m=INT_MIN,id=0;
		for(int j=1;j<=3;j++)
			if(a[i][j]>m)m=a[i][j],id=j;
		d[i]=id;
	}
	for(int i=1;i<=n;i++)
	{
		if(d[i]==1)x++;
		else if(d[i]==2)y++;
		else z++;
	}
	if(x>n/2)work(x,1),f();
	else if(y>n/2)work(y,2),f();
	else if(z>n/2)work(z,3),f();
	return ;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=in();
	while(t--)
	{
		n=in();
		ans=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)a[i][j]=in();
		f();
		for(int i=1;i<=n;i++)
		{
			int m=INT_MIN;
			for(int j=1;j<=3;j++)
				if(a[i][j]>m)m=a[i][j];
			ans+=m;
			out(m),putchar(' ');
		}
		out(ans);
		putchar('\n');
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/