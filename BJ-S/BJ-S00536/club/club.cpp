#include<bits/stdc++.h>
using namespace std;

const int N=100005;
#define LL long long

int t;
int n;
int a[N][3],d[N];
int num[3],mx;
int b[N],m;
int oth1,oth2;
LL ans;

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
		}
		num[0]=num[1]=num[2]=0;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			int tmp=max(a[i][0],max(a[i][1],a[i][2]));
			d[i]=0;
			if (a[i][1]==tmp) d[i]=1;
			if (a[i][2]==tmp) d[i]=2;
			num[d[i]]++;
			ans+=tmp;
			// printf("%d mx:%d(%d)\n",i,mx,d[i]);
		}
		// printf("ans:%lld\n",ans);
		mx=0;
		if (num[1]>num[mx]) mx=1;
		if (num[2]>num[mx]) mx=2;
		if (num[mx]>(n>>1))
		{
			// printf("num[%d]=%d\n",mx,num[mx]);
			oth1=1,oth2=2;
			if (mx==1) oth1=0;
			if (mx==2) oth2=0;
			m=0;
			for(int i=1;i<=n;i++)
			{
				if (d[i]==mx)
				{
					b[++m]=max(a[i][oth1],a[i][oth2])-a[i][mx];
					// printf("b[%d]=%d\n",m,b[m]);
				}
			}
			sort(b+1,b+m+1,greater<int>());
			for (int i=1;i<=num[mx]-(n>>1);i++)
			{
				// printf("%d\n",b[i]);
				ans+=b[i];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}