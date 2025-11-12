#include<bits/stdc++.h>
using namespace std;
#define N 100005
long long t,n,zd,mamax;
struct my_node
{
	long long d[3];
}a[N];
void dfs(long long x1,long long x2,long long x3,long long jg,long long sum)
{
	if(jg==n)
	{	
		mamax=max(mamax,sum);
		return;
}
	for(int i=0;i<3;i++)
	{
		if((x1==n/2&&i==0)||(x2==n/2&&i==1)||(x3==n/2&&i==2))continue;
		if(i==0)
		dfs(x1+1,x2,x3,jg+1,sum+a[jg].d[0]);
		if(i==1)
		dfs(x1,x2+1,x3,jg+1,sum+a[jg].d[1]);
		if(i==2)
		dfs(x1,x2,x3+1,jg+1,sum+a[jg].d[2]);
	}
}

int main()
{
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
cin>>t;
while(t--)  
{mamax=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&a[i].d[0]);
		scanf("%lld",&a[i].d[1]);
		scanf("%lld",&a[i].d[2]);
	}
	dfs(0,0,0,0,0);
	cout<<mamax<<endl;
}
return 0;
}
