#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define il inline 

const int maxn=1e5+5;

int n, sum, t, x, y, z, cnt, ans, fit, sec, pot;
int a[5];
int v[maxn], o[maxn], p[maxn];

il int read()
{
	int num=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9'){num=(num<<3)+(num<<1)+(c^48);c=getchar();}
	return num*f;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--)
	{
		x=0;
		y=0;
		z=0;
		ans=0;
		n=read();
		sum=n/2;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++) a[j]=0;
			sec=0;
			fit=0;
			pot=1;
			for(int j=1;j<=3;j++)
			{
				a[j]=read();
				if(a[j]>fit){
					fit=a[j];
					pot=j;
				}
			}
			ans+=fit;
			for(int j=1;j<=3;j++)
			{
				if(j==pot) continue;
				if(a[j]>sec) sec=a[j];
			}
			if(pot==1) v[++x]=fit-sec;
			if(pot==2) o[++y]=fit-sec;
			if(pot==3) p[++z]=fit-sec;
		}
		if(y>sum)
		{
			cnt=y-sum;
			sort(o+1,o+y+1);
			for(int i=1;i<=cnt;i++) ans-=o[i];
		}
		if(z>sum)
		{
			cnt=z-sum;
			sort(p+1,p+z+1);
			for(int i=1;i<=cnt;i++) ans-=p[i];
		}
		if(x>sum)
		{
			cnt=x-sum;
			sort(v+1,v+x+1);
			for(int i=1;i<=cnt;i++) ans-=v[i];
		}
		cout << ans << endl;
	}
	return 0;
}
