#include<bits/stdc++.h>
#define maxn 100005
#define pii std::pair<int,int>
#define fi first
#define sc second
int T,n,a[maxn][4],b[4],ans;
std::priority_queue<pii>q[3];
inline int read()
{
	int x = 0,f = 1;char ch = getchar();
	while(ch<'0'||ch>'9')f = ch == '-'?-f:f,ch = getchar();
	while(ch>='0'&&ch<='9')x = (x<<3)+(x<<1)+(ch^'0'),ch = getchar();
	return x*f;
}
inline void write(int x)
{
	if(x<0)x = -x,putchar('-');
	static char sta[30];int top = 0;
	do sta[top++] = x%10,x/=10;while(x);
	while(top)putchar(sta[--top]^'0');
	putchar('\n');
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T = read();
	while(T--)
	{
		n = read(),ans = 0;
		for(int i = 1;i<=n;++i)
			for(int j = 0;j<3;++j)
				a[i][j] = read();
		for(int i = 1,max,smax,ssmax;i<=n;++i)
		{
			for(int j = 0;j<3;++j)
			{
				if(q[j].size() == (n>>1))
					b[j] = a[i][j]+q[j].top().fi;
				else b[j] = a[i][j];
			}
			max = 3;
			for(int j = 0;j<3;++j)
				if(b[j]>b[max])max = j;
			ans+=b[max];
			if(q[max].size() == (n>>1))
			{
				smax = 3,ssmax = 0;
				int p = q[max].top().sc;
				for(int j = 0;j<3;++j)if(j!=max)
					if(a[p][j]>a[p][smax])smax = j;
				for(int j = 0;j<3;++j)if(j!=smax)
					ssmax = std::max(ssmax,a[p][j]);
				q[max].pop(),q[smax].push(pii(ssmax-smax,p));
			}
			smax = 0;
			for(int j = 0;j<3;++j)if(j!=max)
				smax = std::max(smax,a[i][j]);
			q[max].push(pii(smax-a[i][max],smax));
		}
		for(int i = 0;i<3;++i)
			while(!q[i].empty())
				q[i].pop();
		write(ans);
	}
	return 0;
}
//3
//4
//4 2 1
//3 2 4
//5 3 4
//3 5 1
//4
//0 1 0
//0 1 0
//0 2 0
//0 2 0
//2
//10 9 8
//4 0 0

