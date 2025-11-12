#include<cstdio>
#include<vector>
bool A=1,B=1;
int n,k,cnt1=0,cnt0=0,maxn=0;
long long ans=0;
std::vector<int> a,s,l,r;
inline int h(int i,int chosed)
{
	return l.size()-i+chosed;
}
void dfs(unsigned int i,int chosed,std::vector<bool> vis)
{
	if(i<l.size()&&h(i,chosed)>ans)
	{
		dfs(i+1,chosed,vis);
		bool f=1;
		for(int j=l[i];j<=r[i];++j)
		{
			if(vis[j]==1)
			{
				f=0;
				break;
			}
		}
		if(f)
		{
			for(int j=l[i];j<=r[i];++j)
			{
				vis[j]=1;
			}
			dfs(i+1,chosed+1,vis);
		}
	}
	else if(i>=l.size())
	{
		if(chosed>ans)
		{
			ans=chosed;
		}
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	a.resize(n+1);
	s.resize(n+1);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		s[i]=(s[i-1]^a[i]);
		if(a[i]!=1)A=0;
		if(a[i]>1)B=0;
		if(a[i]==0)++cnt0;
		if(a[i]==1)++cnt1;
		if(maxn<a[i])maxn=a[i];
	}
	if(k==0&&A)
	{
		printf("%d",n>>1);
		return 0;
	}
	if(k==1&&A)
	{
		printf("%d",n);
		return 0;
	}
	if(k==0&&B)
	{
		printf("%d",(cnt1>>1)+cnt0);
		return 0;
	}
	if(k==1&&B)
	{
		printf("%d",cnt1);
		return 0;
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=i;j<=n;++j)
		{
			if((s[j]^s[i-1])==k)
			{
				l.push_back(i);
				r.push_back(j);
			}
		}
	}
	std::vector<bool> vis(n+1,0);
	dfs(0,0,vis);
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}