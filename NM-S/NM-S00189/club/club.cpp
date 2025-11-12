#include<bits/stdc++.h>
#define int long long
#define N 100005
using namespace std;
constexpr int INF=0x3f3f3f3f3f3f3f3f;

struct str
{
	int x;
	int y;
	int z;
}a[N];

int T;
int n;

int s1,s2,s3;
int num,cnt,ans;
int num1,num2,num3;
array<array<int,5>,N> dp;

bool h1,h2;

void dfs(int rt,int n1,int n2,int n3,int sum)
{
	if(n1>=(n>>1)+1 || n2>=(n>>1)+1 || n3>=(n>>1)+1 ) return;
	else if(rt==n+1)
	{
		ans=max(ans,sum);
		return;
	}
	
	dfs(rt+1,n1+1,n2,n3,sum+a[rt].x);
	dfs(rt+1,n1,n2+1,n3,sum+a[rt].y);
	dfs(rt+1,n1,n2,n3+1,sum+a[rt].z);
}

bool cmp(str l,str r)
{
	if(l.x==r.x)
	{
		if(l.y==r.y) return l.z>r.z;
		else return l.y>r.y;
	}
	else return l.x>r.x;
}

bool hmp(str l,str r)
{
	if(l.z==r.z) return l.x>r.x;
	else return l.z>r.z;
}

signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>T;
	while(T--)
	{
		cin>>n;
		s1=s2=s3=1;
		num1=num2=num3=0;
		
		ans=0;
		h1=h2=true;
		
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i].x);
			scanf("%lld",&a[i].y);
			scanf("%lld",&a[i].z);
			
			if(a[i].y) h1=false;
			if(a[i].z) h2=false;
		}
		
		if(h1 && h2)
		{
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=(n<<1);i++)
			ans+=a[i].x;
			
			printf("%lld\n",ans);
			continue;
		}
		else if(h2)
		{
			for(int i=1;i<=n;i++)
			a[i].z=abs(a[i].x-a[i].y);
			sort(a+1,a+1+n,hmp);
			
			for(int i=1;i<=n;i++)
			if(num1>=(n>>1) ) ans+=a[i].y;
			else if(num2>=(n>>1) ) ans+=a[i].x;
			else
			{
				if(a[i].x>a[i].y) ans+=a[i].x,num1++;
				else ans+=a[i].y,num2++;
			}
			
			printf("%lld\n",ans);
			continue;
		}
		else if(n<=20)
		{
			dfs(1,0,0,0,0);
			printf("%lld\n",ans);
			continue;
		}
		sort(a+1,a+1+n,cmp);

		dp.at(1).at(1)=a[1].x;
		dp.at(1).at(2)=a[1].y;
		dp.at(1).at(3)=a[1].z;
		dp.at(1).at(0)=max({dp.at(1).at(1),dp.at(1).at(2),dp.at(1).at(3)});
		
		if(dp.at(1).at(0)==dp.at(1).at(1) ) num1++;
		else if(dp.at(1).at(0)==dp.at(1).at(2) ) num2++;
		else if(dp.at(1).at(0)==dp.at(1).at(3) ) num3++;
		
		for(int i=2;i<=n;i++)
		{
			dp.at(i).at(1)=dp.at(i-1).at(0)+a[i].x;
			dp.at(i).at(2)=dp.at(i-1).at(0)+a[i].y;
			dp.at(i).at(3)=dp.at(i-1).at(0)+a[i].z;
			
			num=max({dp.at(i).at(1),dp.at(i).at(2),dp.at(i).at(3)});
			if(num==dp.at(i).at(1) ) cnt=1;
			else if(num==dp.at(i).at(2) ) cnt=2;
			else if(num==dp.at(i).at(3) ) cnt=3;
			
			if(num1>=(n>>1) ) dp.at(i).at(1)=-1;
			if(num2>=(n>>1) ) dp.at(i).at(2)=-1;
			if(num3>=(n>>1) ) dp.at(i).at(3)=-1;
			ans=dp.at(i).at(0)=max({dp.at(i).at(1),dp.at(i).at(2),dp.at(i).at(3)});
			
			if(num!=dp.at(i).at(0) )
			{
				dp.at(i).at(0)=num;
				if(cnt==1) dp.at(i).at(0)-=a[s1].x;
				else if(cnt==2)	dp.at(i).at(0)-=a[s2].y;
				else dp.at(i).at(0)-=a[s3].z;
				
				if(cnt==1) a[s1].x=-1;
				else if(cnt==2)	a[s2].y=-1;
				else a[s3].z=-1;
				
				num=max({a[s1].x,a[s2].y,a[s3].z});
				if(num==INF) num=min({a[s1].x,a[s2].y,a[s3].z});
				dp.at(i).at(0)+=num;
				dp.at(i).at(0)=max(ans,dp.at(i).at(0) );
				
				if(cnt==1) a[s1].x=INF;
				else if(cnt==2)	a[s2].y=INF;
				else a[s3].z=INF;

				if(dp.at(i).at(0)==ans)
				{
					if(dp.at(i).at(0)==dp.at(i).at(1) ) num1++;
					else if(dp.at(i).at(0)==dp.at(i).at(2) ) num2++;
					else if(dp.at(i).at(0)==dp.at(i).at(3) ) num3++;
				}
				else
				{
					if(num==a[s1].x) num1++;
					else if(num==a[s2].y) num2++;
					else if(num==a[s3].z) num3++;
				}
			}
			else
			{
				if(dp.at(i).at(0)==dp.at(i).at(1) ) num1++;
				else if(dp.at(i).at(0)==dp.at(i).at(2) ) num2++;
				else if(dp.at(i).at(0)==dp.at(i).at(3) ) num3++;
			}
			
			s1=min(a[s1].x,a[i].x);
			s2=min(a[s2].y,a[i].y);
			s3=min(a[s3].z,a[i].z);
		}
		
		printf("%lld\n",dp.at(n).at(0) );
	}
	return 0;
}
