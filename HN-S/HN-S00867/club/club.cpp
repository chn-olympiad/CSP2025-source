#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
int cnt[5];
struct node
{
	int x,id;
}a[N][5];
struct node1
{
	int Max,id,ID,LA,ld;
}A[N];
bool cmp(node q,node p)
{
	return q.x>p.x;
}
bool cmp1(node1 q,node1 p)
{
	return q.Max+p.LA>q.LA+p.Max;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1].x>>a[i][2].x>>a[i][3].x;
			a[i][1].id=1;
			a[i][2].id=2;
			a[i][3].id=3;
			sort(a[i]+1,a[i]+3+1,cmp);
			A[i].Max=a[i][1].x;
			A[i].id=i;
			A[i].ID=a[i][1].id;
			A[i].LA=a[i][2].x;
			A[i].ld=a[i][2].id;
		}
		cnt[1]=cnt[2]=cnt[3]=0;
		sort(A+1,A+n+1,cmp1);
		int ans=0,m=0;
		for(int i=1;i<=n;i++)
		{
			if(cnt[A[i].ID]+1>n/2)
			{
				ans+=A[i].LA;
				cnt[A[i].ld]++;
			}
			else
			{
				cnt[A[i].ID]++;
				ans+=A[i].Max;
			}
		}
		cout<<ans<<"\n";
	}
    return 0;
}
/*
1
10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926
3:18961+19722+
*/
