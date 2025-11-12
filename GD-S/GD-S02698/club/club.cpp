#include<bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;

inline void read(int &x)
{
	int f=1; x=0;
	char ch=getchar();
	while (ch<'0' || ch>'9')
	{
		if (ch=='-') f=-1;
		ch=getchar();
	}
	while (ch>='0' && ch<='9')
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	x*=f;
}
int n,ch[100005],cnt[4];
struct node
{
	int v,id,type;
	bool operator < (const node &other) const {return v>other.v;}
} a[300005];
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	read(t);
	while (t--)
	{
		memset(ch,0,sizeof(ch));
		memset(cnt,0,sizeof(cnt));
		read(n);
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=3;j++)
			{
				int p=(i-1)*3+j;
				read(a[p].v);
				a[p].id=i,a[p].type=j;
			}
		}
		sort(a+1,a+n*3+1);
		int sum=0,l=(n>>1);
		for (int i=1;i<=n*3;i++)
		{
			if (!ch[a[i].id] && cnt[a[i].type]<l)
			{
				sum+=a[i].v;
				ch[a[i].id]=1,cnt[a[i].type]++;
			}
		}
		cout << sum << endl;
	}
	return 0;
}
