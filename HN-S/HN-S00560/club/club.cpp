#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,m,ans;
int cnt[4];
inline int input()
{
	char ch=getchar();
	int res=0;
	while(ch<'0'||ch>'9')
		ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		res=(res<<3)+(res<<1)+(ch^48);
		ch=getchar();
	}
	return res;
}
struct val
{
	int v1,v2,id1,id2;
}a[N];
struct node
{
	int x,y;
};
inline bool cmp1(node x,node y)
{
	return x.x>y.x;
}
inline bool cmp2(val x,val y)
{
	return (x.v1-x.v2)>(y.v1-y.v2);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=input();
	while(t--)
	{
		n=input();
		m=n/2;
		for(register int i=1;i<=n;++i)
		{
			node x[4];
			x[1].x=input();
			x[2].x=input();
			x[3].x=input();
			x[1].y=1;
			x[2].y=2;
			x[3].y=3;
			sort(x+1,x+4,cmp1);
			a[i].v1=x[1].x;
			a[i].v2=x[2].x;
			a[i].id1=x[1].y;
			a[i].id2=x[2].y;
		}
		sort(a+1,a+n+1,cmp2);
		cnt[1]=cnt[2]=cnt[3]=ans=0;
		for(register int i=1;i<=n;++i)
		{
			if(cnt[a[i].id1]<m)
			{
				++cnt[a[i].id1];
				ans+=a[i].v1;
			}
			else
			{
				++cnt[a[i].id2];
				ans+=a[i].v2;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
