#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 7;
int n;
struct stu
{
	int a,b,c,d,e;
}A[N];
bool cmp(stu a,stu b)
{
	return a.d < b.d;
}
void solve()
{
	scanf("%d",&n);
	int cnt1 = 0,cnt2 = 0,cnt3 = 0;
	long long cnt = 0;
	for(int i = 1;i <= n;++i)
	{
		scanf("%d%d%d",&A[i].a,&A[i].b,&A[i].c);
		if(A[i].a >= A[i].b && A[i].b >= A[i].c) A[i].d = A[i].a - A[i].b,A[i].e = 1,++cnt1;//a>b>c
		else if(A[i].a >= A[i].b && A[i].a >= A[i].c && A[i].c >= A[i].b) A[i].d = A[i].a - A[i].c,A[i].e = 1,++cnt1; //a>c>b
		else if(A[i].b >= A[i].a && A[i].a >= A[i].c) A[i].d = A[i].b - A[i].a,++cnt2,A[i].e = 2;//b>a>c
		else if(A[i].b >= A[i].a && A[i].b >= A[i].c && A[i].a <= A[i].c) A[i].d = A[i].b - A[i].c,++cnt2,A[i].e = 2;//b>c>a
		else if(A[i].c >= A[i].a && A[i].a >= A[i].b) A[i].d = A[i].c - A[i].a,++cnt3,A[i].e = 3;//c>a>b
		else if(A[i].c >= A[i].a && A[i].c >= A[i].b && A[i].a <= A[i].b) A[i].d = A[i].c - A[i].b,++cnt3,A[i].e = 3;//c>b>a
		cnt += max(max(A[i].a,A[i].b),A[i].c);
	}
	if(cnt1 <= n / 2 && cnt2 <= n / 2 && cnt3 <= n / 2)
	{
		printf("%lld\n",cnt);
	}
	else
	{
		sort(A + 1,A + 1 + n,cmp);
		if(cnt1 > n / 2)
		{
			int p = cnt1 - n / 2;
			for(int i = 1,j = 0;i <= n;++i)
			{
				if(j == p) break;
				if(A[i].e == 1) ++j,cnt -= A[i].d;
			}
		}
		else if(cnt2 > n / 2)
		{
			int p = cnt2 - n / 2;
			for(int i = 1,j = 0;i <= n;++i)
			{
				if(j == p) break;
				if(A[i].e == 2) ++j,cnt -= A[i].d;
			}
		}
		else if(cnt3 > n / 2)
		{
			int p = cnt3 - n / 2;
			for(int i = 1,j = 0;i <= n;++i)
			{
				if(j == p) break;
				if(A[i].e == 3) ++j,cnt -= A[i].d;
			}
		}
		printf("%lld\n",cnt);
	}
	for(int i = 1;i <= n;++i) A[i].a = A[i].b = A[i].c = A[i].d = A[i].e = 0;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	solve();
	return 0;
}
