#include <bits/stdc++.h> //3,区间不相交 ,未写最小区间长度 
using namespace std;

long long n,k,a[500005];
bool vis[500005];
int cnt=0;

struct num
{
	long long x,y,len;
}dis[500005]; //存i,j 

bool check(int l,int r)
{
	for (int i=l;i<=r;i++)
	{
		if (vis[i]) return 0;
	}
	
	for (int i=l;i<=r;i++) vis[i]=1;
	return 1;
 } 
 
bool cmp(num o,num p)
{
	return o.len<p.len;
}

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for (int i=1;i<=n;i++) cin>>a[i];
	
	long long ans=0,q=0;
	for (int i=1;i<=n;i++)
	{
		for (int j=i;j<=n;j++)
		{
			for (int k=i;k<=j;k++) ans=ans^a[k];
			if (ans==k) q++,dis[q].x=i,dis[q].y=j,dis[q].len=j-i+1/*,cout<<"ans="<<ans<<" i="<<i<<" j="<<j<<endl*/;
			ans=0;
		}
	}
	
	sort(dis+1,dis+q,cmp);
	
	for (long long i=1;i<=q;i++)
	{
		if (check(dis[i].x,dis[i].y)) cnt++;
	}
	
	cout<<cnt;
	return 0;
 } 
