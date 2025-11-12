/*
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
const int N=1e5+5;
struct stu{
	int a[4];
};
stu s[N];
vector<stu> st[4];
int num[4];
int n;
bool c1(stu x,stu y)
{
	int tn[2],dx,dy;
	tn[0]=2;
	tn[1]=3;
	dx=max(x.a[tn[0]]-x.a[1],x.a[tn[1]]-x.a[1]);
	dy=max(y.a[tn[0]]-y.a[1],y.a[tn[1]]-y.a[1]);
	return dx>dy;
}
bool c2(stu x,stu y)
{
	int tn[2],dx,dy;
	tn[0]=1;
	tn[1]=3;
	dx=max(x.a[tn[0]]-x.a[2],x.a[tn[1]]-x.a[2]);
	dy=max(y.a[tn[0]]-y.a[2],y.a[tn[1]]-y.a[2]);
	return dx>dy;
}
bool c3(stu x,stu y)
{
	int tn[2],dx,dy;
	tn[0]=1;
	tn[1]=2;
	dx=max(x.a[tn[0]]-x.a[3],x.a[tn[1]]-x.a[3]);
	dy=max(y.a[tn[0]]-y.a[3],y.a[tn[1]]-y.a[3]);
	return dx>dy;
}
inline void solve()
{
	stu unt;
	st[1].push_back(unt);
	st[2].push_back(unt);
	st[2].push_back(unt);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d%d",&s[i].a[1],&s[i].a[2],&s[i].a[3]);
		if(s[i].a[1]>=s[i].a[2]&&s[i].a[1]>=s[i].a[3])
		{
			num[1]++;
			st[1].push_back(s[i]);
		}
		else if(s[i].a[2]>s[i].a[3])
		{
			num[2]++;
			st[2].push_back(s[i]);
		}
		else
		{
			num[3]++;
			st[3].push_back(s[i]);
		}
	}
	int i1=1,i2=1,i3=1;
	if(num[1]-i1+1>(n>>1))
	{
		sort(&st[1][0]+1,&st[1][0]+num[1]+1,c1);
		while(num[1]-i1+1>(n>>1))
		{
			int tt;
			if(st[1][i1].a[2]>st[1][i1].a[3]) tt=2;
			else tt=3;
			num[tt]++;
			st[tt].push_back(st[1][i1]);
			i1++;
		}
	}
	if(num[2]-i2+1>(n>>1))
	{
		sort(&st[2][0]+1,&st[2][0]+num[2]+1,c2);
		while(num[2]-i2+1>(n>>1))
		{
			int tt;
			if(st[2][i2].a[1]>st[2][i2].a[3]) tt=1;
			else tt=3;
			num[tt]++;
			st[tt].push_back(st[2][i2]);
			i2++;
		}
	}
	if(num[3]-i3+1>(n>>1))
	{
		sort(&st[3][0]+1,&st[3][0]+num[3]+1,c3);
		while(num[3]-i3+1>(n>>1))
		{
			int tt;
			if(st[3][i3].a[1]>st[3][i3].a[2]) tt=1;
			else tt=2;
			num[tt]++;
			st[tt].push_back(st[3][i3]);
			i3++;
		}
	}
	long long ans=0;
	for(int i=i1;i<=num[1];++i)
	{
		ans+=(long long)st[1][i].a[1];
	}
	for(int i=i2;i<=num[2];++i)
	{
		ans+=(long long)st[2][i].a[2];
	}
	for(int i=i3;i<=num[3];++i)
	{
		ans+=(long long)st[3][i].a[3];
	}
	printf("%lld\n",ans);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		for(int i=1;i<=3;++i)
		{
			st[i].clear();
			num[i]=0;
		}
		solve();
	}
	fclose(stdin);
	fclose(stdout);
}
*/
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e5+5;
struct stu{
	int s[4];
}a[N];
int n;
bool c(stu a,stu b)
{
	return a.s[2]-a.s[1]>b.s[2]-b.s[1];
}
void solve()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d%d%d",&a[i].s[1],&a[i].s[2],&a[i].s[3]);
	long long ans=0;
	sort(a+1,a+1+n,c);
	for(int i=1;i<=n>>1;++i)
	{
		ans+=(long long)a[i].s[2];
	}
	for(int i=(n>>1)+1;i<=n;++i)
	{
		ans+=(long long)a[i].s[1];
	}
	printf("%lld\n",ans);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
