#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cstring>
#define N 100005
#define M 5
using namespace std;
int T;
int n,ans;
struct node1
{
	int num;
	int id;
}a[N][M];
bool cmp1(node1 x,node1 y)
{
	return x.num>y.num;
}
struct node2
{
	int num;
	int id;
}b[N];
bool cmp2(node2 x,node2 y)
{
	return x.num>y.num;
}
int cnt[M];
void solve()
{
	ans=0;
	memset(cnt,0,sizeof(cnt));
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][1].num>>a[i][2].num>>a[i][3].num;
		a[i][1].id=1,a[i][2].id=2,a[i][3].id=3;
	    sort(a[i]+1,a[i]+4,cmp1);
	    b[i].num=a[i][1].num-a[i][2].num;
	    b[i].id=i;
	}
	sort(b+1,b+n+1,cmp2);
	for(int i=1;i<=n;i++)
	{
		if(cnt[a[b[i].id][1].id]>=n/2)
		{
		    ans+=a[b[i].id][2].num;
		    cnt[a[b[i].id][2].id]++;
		}
		else
		{
			ans+=a[b[i].id][1].num;
			cnt[a[b[i].id][1].id]++;
		}
	}
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	    solve();
	return 0;
}
