#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
namespace io
{
	void read()
	{
		return;
	}
	template<typename nowtype,typename ...nexttype>
	void read(nowtype &now,nexttype &...next)
	{
		now=0;
		char c=getchar();
		bool sign(false);
#define isdigit(c) ((c)>='0'&&(c)<='9')
		while(!isdigit(c)){if(c=='-') sign=true;c=getchar();}
		while(isdigit(c)){now=(now<<1)+(now<<3)+(c^48);c=getchar();}
#undef isdigit
		if(sign) now=-now;
		read(next...);
	}
	template<typename nowtype>
	void write(nowtype now,char end='\n')
	{
		if(now<0) putchar('-');
		int c[40],top(0);
#define abs(x) ((x)<0?-(x):(x))
		do c[top++]=abs(now%10),now/=10;while(now);
#undef abs
		while(top) putchar(c[--top]+48);
		putchar(end);
	}
	template<typename nowtype,typename ...nexttype>
	void write(nowtype now,char sep,nexttype ...next)
	{
		if(now<0) putchar('-');
		int c[40],top(0);
#define abs(x) ((x)<0?-(x):(x))
		do c[top++]=abs(now%10),now/=10;while(now);
#undef abs
		while(top) putchar(c[--top]+48);
		putchar(sep);
		write(next...);
	}
}
using namespace io;
namespace Sol
{
	typedef long long ll;
	typedef unsigned long long ull;
	const int const1=1e5+10;
	struct info{int max,med,min,change;};
	std::vector<info> inf;
	std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int> >,std::less<std::pair<int,int> > > q[4];
	int a[const1][4],club[4];
	void solve()
	{
		int i,j,n,max,med,min;
		ll ans(0);
		read(n);
		for(i=1;i<=3;++i)
		{
			while(!q[i].empty()) q[i].pop();
			club[i]=0;
		}
		inf.clear();
		inf.push_back({0,0,0,0});
		for(i=1;i<=n;++i)
		{
			read(a[i][1],a[i][2],a[i][3]);
			max=med=min=1;
			for(j=1;j<=3;++j)
			{
				if(a[i][j]>a[i][max]) max=j;
				if(a[i][j]<a[i][min]) min=j;
			}
			med=6-max-min;
			inf.push_back({max,med,min,a[i][med]-a[i][max]});
			if(club[max]<(n>>1))
			{
				ans+=a[i][max];
				++club[max];
				q[max].push(std::make_pair(a[i][med]-a[i][max],i));
			}
			else
			{
				j=q[max].top().second;
				if(a[i][max]>a[j][inf[j].max]||a[i][med]<=a[i][max]+q[max].top().first)
				{
					q[max].pop();
					++club[inf[j].med];
					ans+=inf[j].change;
					ans+=a[i][max];
					q[max].push(std::make_pair(a[i][med]-a[i][max],i));
				}
				else
				{
					ans+=a[i][med];
					++club[med];
				}
			}
		}
		write(ans);
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	read(t);
	while(t--) Sol::solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
