#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
ll ans,sum[10],cnt;
int flag[N],ch,n,T;
struct Node
{
	int id,sum,s;
}a[3*N];
bool cmp(Node x,Node y)
{
	return x.id>y.id;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while (T--)
	{
		cnt=0;
		ch=0;
		cin >> n;
		for (int i=1; i<=n; i++)
		{
			int x,y,z;
			cin >> x >> y >> z;
			a[++cnt].sum=x;
			a[cnt].id=i;
			a[cnt].s=1;
			a[++cnt].sum=y;
			a[cnt].id=i;
			a[cnt].s=2;
			a[++cnt].sum=z;
			a[cnt].id=i;
			a[cnt].s=3;
			flag[i]=1;
		}
		sort(a+1,a+cnt+1,cmp);
		for (int i=1; i<=cnt; i++)
		{
			if (flag[a[i].id]==1 && a[i].s!=ch)
			{
				ans+=a[i].sum;
				flag[a[i].id]=0;
				sum[a[i].s]++;
				if (sum[a[i].s]==n/2)
				{
					ch=a[i].s;
				}
			}
			
		}
		printf("%lld\n",ans);
		for (int i=1; i<=cnt; i++)
		{
			a[i].id=0;
			a[i].s=0;
			a[i].sum=0;
		}
		for (int i=0; i<=7; i++)
		{
			sum[i]=0;
		}
	}
	return 0;
}
