#include<bits/stdc++.h>
using namespace std;
template<typename T>void qr(T &x)
{
	x=0;
	int f=1;
	char c=getchar();
	for(;!isdigit(c);c=getchar())
	{
		if(c=='-')
		{
			f=-1;
		}
	}
	for(;isdigit(c);c=getchar())
	{
		x=x*10+c-48;
	}
	x=x*f;
}
template<typename T>void qw(T x)
{
	if(x<0)
	{
		x=-x;
		putchar('-');
	}
	if(x/10)
	{
		qw(x/10);
	}
	putchar(x%10+48);
}
typedef long long LL;
const int N=2e5+10;
struct node
{
	int x,id;
}a[N][4];
LL	ans;
bool cmp(node A,node B)
{
	return A.x>B.x;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	qr(T);
	while(T--)
	{
		ans=0;
		int n;
		qr(n);
		priority_queue<int,vector<int>,greater<int>>Q[4];
		for(int i=1;i<=n;i++)
		{	
			for(int j=1;j<=3;j++)
			{
				qr(a[i][j].x);
				a[i][j].id=j;
			}
			sort(a[i]+1,a[i]+3+1,cmp);
			ans+=a[i][1].x;
			Q[a[i][1].id].push(a[i][1].x-a[i][2].x);
		}
		for(int i=1;i<=3;i++)
		{
			if(Q[i].size()>n/2)
			{
				while(Q[i].size()>n/2)
				{
					int t=Q[i].top();
					Q[i].pop();
					ans-=t;
				}
			}
		}
		qw(ans);
		puts("");
	}
	return 0;
}
