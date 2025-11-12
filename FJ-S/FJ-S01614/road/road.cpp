#include<bits/stdc++.h>
using namespace std;
struct str1
{
	int val;
	int pos;
};
struct str
{
	vector <str1> v;
}l[10015];
int l2[10015];
bool isv[10015];
int n,m,k;
long long find2(long long ans)
{
	queue <str1> q;
	for(auto i:l[1].v) q.push(i);
	for(int i=1;i<=n;i++) isv[i]=false;
	while(!q.empty())
	{
		queue <str1> q2;
		int minval=INT_MAX;
		int minpos=0;
		while(!q.empty())
		{
			str1 strn=q.front();
			if(!isv[strn.pos]) q2.push(strn);
			if((!isv[strn.pos])&&strn.val<minval)
			{
				minval=strn.val;
				minpos=strn.pos;
			}
			q.pop();
		}
		isv[minpos]=true;
		ans+=minval;
		while(!q2.empty())
		{
			str1 strm=q2.front();
			q.push(strm);
			q2.pop();
		}
	}
	return ans;
}
long long find(int now,long long cost)
{
	if(now>k) return find2(cost);
	long long ans1=998244353;
	isv[n+now]=false;
	ans1=min(ans1,find(now,cost+l2[now]));
	isv[n+now]=true;
	ans1=min(ans1,find(now,cost));
	return ans1;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		int ui,vi,wi;
		scanf("%d%d%d",&ui,&vi,&wi);
		str1 strx;
		str1 stry;
		strx.pos=vi;
		strx.val=wi;
		stry.pos=ui;
		stry.val=wi;
		l[ui].v.push_back(strx);
		l[vi].v.push_back(stry);
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&l2[i]);
		for(int j=1;j<=n;j++)
		{
			int x;
			scanf("%d",&x);
			str1 strx;
			str1 stry;
			strx.pos=j;
			strx.val=x;
			stry.pos=n+i;
			stry.val=x;
			l[n+i].v.push_back(strx);
			l[j].v.push_back(stry);
		}
	}
	printf("%lld",find(1,0));
	return 0;
}
