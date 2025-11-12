# include <cstdio>
# include <algorithm>
# include <random>
# define int long long
using namespace std;
int T,n,a[200007][3],s[200007][2];
std::mt19937 rnd(0);
int max(int x,int y){return x>y?x:y;}
void qsort(int x,int y)
{
	int i=x,j=y,mid=s[rnd()%(y-x+1)+x][1];
	while(i<=j)
	{
		while(s[i][1]>mid) i++;
		while(s[j][1]<mid) j--;
		if(i<=j)
		{
			swap(s[i],s[j]);
			i++,j--;
		}
	}
	if(i<y) qsort(i,y);
	if(x<j) qsort(x,j);
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	for(int mayfly=1;mayfly<=T;mayfly++)
	{
		scanf("%lld",&n);
		for(int i=1;i<=n;i++) scanf("%lld%lld%lld",&a[i][0],&a[i][1],&a[i][2]);
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2])
			{
				s[i][0]=0;
				s[i][1]=-a[i][0]+max(a[i][1],a[i][2]);
				ans+=a[i][0];
			}
			else if(a[i][1]>=a[i][2])
			{
				s[i][0]=1;
				s[i][1]=-a[i][1]+max(a[i][0],a[i][2]);
				ans+=a[i][1];
			}
			else
			{
				s[i][0]=2;
				s[i][1]=-a[i][2]+max(a[i][0],a[i][1]);
				ans+=a[i][2];
			}
		}
		qsort(1,n);
		int x1=0,x2=0,x3=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i][0]==0) x1++;
			if(s[i][0]==1) x2++;
			if(s[i][0]==2) x3++;
		}
		for(int i=1;i<=n;i++)
		{
			if(s[i][0]==0)
			{
				if(x1>n/2) x1--,ans+=s[i][1];
			}
			if(s[i][0]==1)
			{
				if(x2>n/2) x2--,ans+=s[i][1];
			}
			if(s[i][0]==2)
			{
				if(x3>n/2) x3--,ans+=s[i][1];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
