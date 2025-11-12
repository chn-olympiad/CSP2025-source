#include<bits/stdc++.h>
#define file(NAME)\
	freopen(NAME".in","r",stdin);\
	freopen(NAME".out","w",stdout);
#define ll long long
#define pii pair<int,int>
#define mk make_pair
#define rep(i,x,y) for(int i=x,y_=y;i<=y_;i++)
#define per(i,x,y) for(int i=y,x_=x;i>=x_;i--)
using namespace std;
char ch;
void rd(int &x)
{
	for(ch=0;ch<'0'||ch>'9';ch=getchar());
	for(x=0;ch>='0'&&ch<='9';x=(x<<1)+(x<<3)+(ch^48),ch=getchar());
}
const int N=1e5+5,M=0,P=998244353;
int n,a[3],g[3],s,z;
priority_queue<int> hp[3];
pii c;
int main()
{
	file("club");
	int T;rd(T);
	while(T--)
	{
		rep(i,0,2) g[i]=0;
		rep(i,0,2) while(!hp[i].empty()) hp[i].pop();
		rd(n),z=0;
		rep(i,1,n)
		{
			c=mk(-1e9,0);
			rep(j,0,2)
			{
				rd(a[j]);
				if(g[j]<n/2) c=max(c,mk(a[j],j));
				else c=max(c,mk(a[j]+hp[j].top(),j));
			}
			if(g[c.second]>=n/2) hp[c.second].pop();
			z+=c.first,g[c.second]++;
			s=-1e9;
			rep(j,0,2) if(j!=c.second) s=max(s,a[j]);
			hp[c.second].push(s-a[c.second]);
		}
		printf("%d\n",z);
	}
	return 0;
}
