#include<bits/stdc++.h>
#define l first
#define r second
using namespace std;
typedef pair<int,int> PII;
const int N=5e5+10;
int n,k,a[N],idx,s[N],cnt;
PII b[N];
queue<int> q[N*2];
map<int,int> mp;
int get(int x)
{
	if(!mp.count(x))mp[x]=++idx;
	return mp[x];
}
bool cmp(PII x,PII y)
{
	return x.r<y.r;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1]^a[i];
		q[get(s[i])].push(i);
	}
	for(int i=0;i<n;i++)
	{
		int x=get(s[i]^k);
		if(q[x].size())
		{
			int r=-1;
			while(q[x].size())
			{
				int t=q[x].front();
				if(t>i)
				{
					r=t;
					break;
				}
				q[x].pop();
			}
			if(r!=-1)b[++cnt]={i+1,r};
		}
	}
	sort(b+1,b+cnt+1,cmp);
	int res=0,ed=0;
	for(int i=1;i<=cnt;i++)
		if(b[i].l>ed)
		{
			res++;
			ed=b[i].r;
		}
	printf("%d",res);
	return 0;
}
