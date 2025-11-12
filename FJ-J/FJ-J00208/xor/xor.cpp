#include<iostream>
#include<map>
#include<vector>
using namespace std;
int n,k,a,s[500005],dp[500005],cnt;
map<int,vector<int> >mp;
struct qujian
{
	int l,r;
}q[500005];
int c[500005];
void change(int x,int y)
{
	for(;x<=n;x+=x&-x)	
		c[x]=max(c[x],y);
}
int ask(int x)
{
	int ans=0;
	for(;x;x-=x&-x)
		ans=max(ans,c[x]);
	return ans;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	mp[0].push_back(0);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a);
		s[i]=s[i-1]^a;
		mp[s[i]].push_back(i);
	}
	for(int i=1;i<=n;i++)
	{
		int g=(k^s[i-1]);
		if(mp[g].size())
		{
			int x=(lower_bound(mp[g].begin(),mp[g].end(),i)-mp[g].begin());
			if(x!=(int)(mp[g].size()))
				q[++cnt]={i,mp[g][x]};
		}
	}
	for(int i=1;i<=cnt;i++)
		change(q[i].r,ask(q[i].l-1)+1);
	printf("%d",ask(n));
	return 0;
}
