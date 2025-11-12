#include <bits/stdc++.h>
using namespace std;
const long long N=100000;
struct csp{
	long long a;
	long long b;
	long long c;
	long long ranka;
	long long rankb;
	long long rankc;
	bool biao=false; 
	long long teshua=0;
	long long teshub=0;
	long long teshuc=0;
}f[N];
bool cmpa(csp x,csp y)
{
	if(x.teshua==y.teshua)
	{
		if(x.ranka==y.ranka)
		{
			return x.a>y.a;
		}
		return x.ranka<y.ranka;
	}
	return x.teshua>y.teshua;
}
bool cmpb(csp x,csp y)
{
	if(x.teshub==y.teshub)
	{
		if(x.rankb==y.rankb)
		{
			return x.b>y.b;
		}
		return x.rankb<y.rankb;
	}
	return x.teshub>y.teshub;
}
bool cmpc(csp x,csp y)
{
	if(x.teshuc==y.teshuc)
	{
		if(x.rankc==y.rankc)
		{
			return x.c>y.c;
		}
		return x.rankc<y.rankc;
	}
	return x.teshuc>y.teshuc;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	long long T;
	cin>>T;
	while(T--)
	{
		long long n;
		cin>>n;
		for(long long i=0;i<n;i++)
		{
			f[i].biao=false;
			cin>>f[i].a>>f[i].b>>f[i].c;
			if(f[i].b==0 && f[i].c==0)
			{
				f[i].teshua=1;
			}
			else if(f[i].a==0 && f[i].b==0)
			{
				f[i].teshuc=1; 
			}
			else if(f[i].c==0 && f[i].a==0)
			{
				f[i].teshub=1;
			}
			if(f[i].a>f[i].b && f[i].a>f[i].c)
			{
				f[i].ranka=1;
				if(f[i].b>f[i].c)
				{
					f[i].rankb=2;
					f[i].rankc=3;
				}
				else if(f[i].b==f[i].c)
				{
					f[i].rankb=2;
					f[i].rankc=2;
				}
				else
				{
					f[i].rankc=2;
					f[i].rankb=3;
				}
			}
			else if(f[i].b>f[i].a && f[i].b>f[i].c)
			{
				f[i].rankb=1;
				if(f[i].a>f[i].c)
				{
					f[i].ranka=2;
					f[i].rankc=3;
				}
				else if(f[i].a==f[i].c)
				{
					f[i].rankc=2;
					f[i].ranka=2;
				}
				else
				{
					f[i].rankc=2;
					f[i].ranka=3;
				}
			}
			else if(f[i].c>f[i].a && f[i].c>f[i].b)
			{
				f[i].rankc=1;
				if(f[i].a>f[i].b)
				{
					f[i].ranka=2;
					f[i].rankb=3;
				}
				else if(f[i].a==f[i].b)
				{
					f[i].rankc=2;
					f[i].ranka=2;
				}
				else
				{
					f[i].rankb=2;
					f[i].ranka=3;
				}
			}
			else
			{
				if(f[i].a==f[i].b)
				{
					f[i].ranka=1;
					f[i].rankb=1;
					f[i].rankc=2;
				}
				else if(f[i].c==f[i].b && f[i].a==f[i].c)
				{
					f[i].ranka=1;
					f[i].rankb=1;
					f[i].rankc=1;
				}
				else if(f[i].a==f[i].c)
				{
					f[i].ranka=1;
					f[i].rankc=1;
					f[i].rankb=2;
				}
				else if(f[i].b==f[i].c)
				{
					f[i].rankb=1;
					f[i].rankc=1;
					f[i].ranka=2;
				}
			}
		}
		long long sum=0;
		//开始计数
		long long zongshu=n;
		sort(f,f+n,cmpa);
		long long cnt=0;
		for(long long i=0;i<(n/2);i++)
		{
			if(cnt>(n/2))
			{
				break;
			}
			if(f[i].ranka>f[i].rankb && zongshu<=(n/2))
			{
				continue;
			}
			sum+=f[i].a;
			f[i].biao=true;
			zongshu--;
			cnt++;
		}
		sort(f,f+n,cmpb);
		cnt=0;
		for(long long i=0;i<n;i++)
		{
			if(cnt>(n/2))
			{
				break;
			}
			if(f[i].biao)
			{
				continue;
			}
			if(f[i].rankb>f[i].rankc && zongshu<=(n/2))
			{
				continue;
			}
			sum+=f[i].b;
			f[i].biao=true;
			cnt++;
			zongshu--;
		}
		sort(f,f+n,cmpc);
		cnt=0;
		for(long long i=0;i<n;i++)
		{
			if(cnt>(n/2))
			{
				break;
			}
			if(f[i].biao)
			{
				continue;
			}
			sum+=f[i].c;
			f[i].biao=true;
			cnt++;
		}
		cout<<sum<<endl;
	}
	//额啊我写了2个小时的代码啊啊啊啊啊啊啊
	//这个大样例为什么这么没有参考性！！！！！！
	//额啊啊啊啊啊结果错了我都不知道我是哪个值没加上啊啊啊啊啊啊啊啊 
	return 0;
}
//一个笑话：T1写了227行(包括本行和其他注释)
//还真有可能一分没有(悲) 
