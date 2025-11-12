#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
//部分分k=0和性质A 
struct node
{
	long long u,v,w;
	
	bool operator<(const node &y) const{
		return w>y.w;
	}
};

long long n,m,k,c,cnt=0,ans=0;
long long bin[10050];//并查集 
node t;
priority_queue<node> q;

long long fin(long long x)
{
	if(bin[x]==x)return x;
	return bin[x]=fin(bin[x]);
}

void hb(long long x,long long y)
{
	bin[fin(x)]=fin(y);
	return;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	scanf("%lld",&n);
	scanf("%lld",&m);
	scanf("%lld",&k);
	
	for(long long i=1;i<=n+k;i++)
		bin[i]=i;
	
	for(long long i=1;i<=m;i++)
	{
		scanf("%lld",&t.u);
		scanf("%lld",&t.v);
		scanf("%lld",&t.w);
		q.push(t);
	}
	
	for(long long i=1;i<=k;i++)
	{
		scanf("%lld",&c);
		ans+=c;
		
		for(long long j=1;j<=n;j++)
		{
			t.u=n+i;
			t.v=j;
			scanf("%lld",&t.w);
			q.push(t);
		}
	}
	
	while(!q.empty() && cnt<n+k-1)
	{
		t=q.top();
		q.pop();
		
		if(fin(t.u)!=fin(t.v))
		{
			ans+=t.w;
			hb(t.u,t.v);
			cnt++;
		}
	}
	
	cout<<ans<<endl;
	
	return 0;
}
