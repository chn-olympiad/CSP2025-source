#include <bits/stdc++.h>
using namespace std;
int a[100005][4],c[4],z;
struct node
{
	int d,id;
}b[100005];
int maxx(int x)
{
	if(a[x][1]>=a[x][2]&&a[x][1]>=a[x][3]) return 1;
	if(a[x][2]>=a[x][1]&&a[x][2]>=a[x][3]) return 2;
	if(a[x][3]>=a[x][1]&&a[x][3]>=a[x][2]) return 3;
}
int ansx(int x)
{
	if(a[x][1]>=a[x][3]&&a[x][3]>=a[x][2]||a[x][2]>=a[x][3]&&a[x][3]>=a[x][1]) return 3;
	if(a[x][1]>=a[x][2]&&a[x][2]>=a[x][3]||a[x][3]>=a[x][2]&&a[x][2]>=a[x][1]) return 2;
	if(a[x][3]>=a[x][1]&&a[x][1]>=a[x][2]||a[x][2]>=a[x][1]&&a[x][1]>=a[x][3]) return 1;
}
int minu(int x)
{
	if(a[x][1]<=a[x][2]&&a[x][1]<=a[x][3]) return abs(a[x][3]-a[x][2]);
	if(a[x][2]<=a[x][1]&&a[x][2]<=a[x][3]) return abs(a[x][1]-a[x][3]);
	if(a[x][3]<=a[x][1]&&a[x][3]<=a[x][2]) return abs(a[x][1]-a[x][2]);
}
bool cmp(node x,node y)
{
	if(x.d!=z||y.d!=z) return x.d==z;
	return minu(x.id)>=minu(y.id);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);	
	int t;
	cin >> t;
	while(t--)
	{
		memset(c,0,sizeof(c));
		int n;
		cin >> n;
		for(int i=1;i<=n;i++)
		{
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			b[i].d=maxx(i);
			b[i].id=i;
			c[b[i].d]++;
		}
		if(c[1]>n/2)
		{
			z=1;
			sort(b+1,b+n+1,cmp);
			for(int i=n/2+1;i<=c[1];i++)
			{
				b[i].d=ansx(b[i].id);
			}
		}
		if(c[2]>n/2)
		{
			z=2;
			sort(b+1,b+n+1,cmp);
			for(int i=n/2+1;i<=c[2];i++)
			{
				b[i].d=ansx(b[i].id);
			}
		}
		if(c[3]>n/2)
		{
			z=3;
			sort(b+1,b+n+1,cmp);
			for(int i=n/2+1;i<=c[3];i++)
			{
				b[i].d=ansx(b[i].id);
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			ans+=a[b[i].id][b[i].d];
		}
		cout << ans << endl;
	} 
	return 0;
} 
