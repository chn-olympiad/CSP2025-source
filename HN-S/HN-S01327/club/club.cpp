#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N=1e5+10;
int T,n,sum[4];
ll ans_,ans,a[N][4],sha[N];
bool flag;

inline bool cmp(ll a,ll b)
{
	return a>b;
}

inline void dfs(int num)
{
	if(num>n)
	{
		ans=max(ans,ans_);
		
		return ;
	}
	
	for(int i=1;i<=3;++i)
	{
		if(sum[i]<n/2)
		{
			ans_+=a[num][i];
			++sum[i];
			dfs(num+1);
			ans_-=a[num][i];
			--sum[i];
		}
	}
	
	return ;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	scanf("%d",&T);
	while(T--)
	{
		flag=0;
		sum[1]=sum[2]=sum[3]=0;
		ans=0;
		
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
		{
			scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
			if((a[i][2]!=0||a[i][3]!=0)&&!flag) flag=1;
		}
		
		
		if(flag) dfs(1);
		else
		{
			for(int i=1;i<=n;++i) sha[i]=a[i][1];
			
			sort(sha+1,sha+1+n,cmp);
			
			for(int i=1;i<=n/2;++i) ans+=sha[i];
		}
		
		printf("%lld\n",ans);
		
	}
	
    return 0;
} 
