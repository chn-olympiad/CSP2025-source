#include<bits/stdc++.h>
using namespace std;
int a[100005][4];
int sy[4];
int join(int i)
{
	if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]) return 1;
	if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]) return 2;
	if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2]) return 3;
	return 0;
}
int s[100005],w;
bool cmp(int a,int b)
{
	return a>b;
}
void solve()
{
	w=sy[1]=sy[2]=sy[3]=0;
	int n,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
	for(int i=1;i<=n;i++)
	{
		int p=join(i);
		ans+=a[i][p];
		sy[p]++;
	}
	int mx=0;
	for(int i=1;i<=3;i++)
	{
		if(sy[i]>n/2) mx=i;
	}
	if(!mx) printf("%d\n",ans);
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(join(i)==mx)
			{
				if(mx==1) s[++w]=max(a[i][2]-a[i][1],a[i][3]-a[i][1]);
				if(mx==2) s[++w]=max(a[i][1]-a[i][2],a[i][3]-a[i][2]);
				if(mx==3) s[++w]=max(a[i][1]-a[i][3],a[i][2]-a[i][3]);
			}
		}
		sort(s+1,s+w+1,cmp);
		int i=1;
		while(sy[mx]!=n/2)
		{
			sy[mx]--;
			ans+=s[i];
			i++;
		}
		printf("%d\n",ans);
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--) solve();
}
