#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,ans;
int a[N][3];
int st[N][3],tp[3];
vector<int> v;

int maxn(int i)
{
	if(a[i][0]>=a[i][1] and a[i][0]>=a[i][2]) return 0;
	else if(a[i][1]>=a[i][0] and a[i][1]>=a[i][2]) return 1;
	else return 2;
}

int secmax(int i)
{
	int val=a[i][0]+a[i][1]+a[i][2]-a[i][maxn(i)]-min(a[i][0],min(a[i][1],a[i][2]));
	if(a[i][0]==val) return 0;
	else if(a[i][1]==val) return 1;
	else return 2;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		tp[0]=tp[1]=tp[2]=0;
		ans=0;
		v.clear();
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
			st[++tp[maxn(i)]][maxn(i)]=i;
			ans+=a[i][maxn(i)];
		}
		if(tp[0]<=n/2 and tp[1]<=n/2 and tp[2]<=n/2)
		{
			printf("%d\n",ans);
			continue;
		}
		int p;
		if(tp[0]>n/2) p=0;
		else if(tp[1]>n/2) p=1;
		else p=2;
		for(int i=1;i<=tp[p];i++)
			v.push_back(a[st[i][p]][secmax(st[i][p])]-a[st[i][p]][maxn(st[i][p])]);
		sort(v.rbegin(),v.rend());
		for(int i=1;i<=tp[p]-n/2;i++)
			ans+=v[i-1];
		printf("%d\n",ans);
	}
	return 0;
}
