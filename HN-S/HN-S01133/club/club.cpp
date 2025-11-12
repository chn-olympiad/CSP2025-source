#include <bits/stdc++.h>
using namespace std;

struct node{
	int a1,a2,a3;
	int maxnyi,maxner;
};
node a[100000+10];
long long maxn=0;
void dfs(int x,int sum,int cnta,int cntb,int cntc,int n)
{
	if(x>n)
	{
		if(cnta<=n/2&&cntb<=n/2&&cntc<=n/2)
		maxn=max(sum*1ll,maxn);
		return ;
	}
    if(cnta<n/2)
    {
    	dfs(x+1,sum+a[x].a1,cnta+1,cntb,cntc,n);
	}
	if(cntb<n/2)
    {
    	dfs(x+1,sum+a[x].a2,cnta,cntb+1,cntc,n);
	}
	if(cntc<n/2)
    {
    	dfs(x+1,sum+a[x].a3,cnta,cntb,cntc+1,n);
	}
}
bool cmp(node a,node b)
{
	return a.a1>b.a1;
}

bool cmp2(node a,node b)
{
	return a.a2>b.a2;
}

bool cmp3(node a,node b)
{
	return a.a3>b.a3;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
		cin>>n;
		memset(a,0,sizeof(a)); 
		bool flag=1,flag2=1,flag3=1;
	    for(int i=1;i<=n;i++)
	    {
	    	cin>>a[i].a1>>a[i].a2>>a[i].a3;
	        if(a[i].a2!=0||a[i].a3!=0)
	        	flag=0;
			if(a[i].a1!=0||a[i].a3!=0)
				flag2=0;
			if(a[i].a2!=0||a[2].a3!=0)
				flag3=0;
		}
	    if(flag==1)
	    {
	    	sort(a+1,a+n+1,cmp);
	    	long long sum=0;
	    	for(int i=1;i<=n/2;i++)
	    	{
	    		sum+=a[i].a1;
			}
			cout<<sum<<"\n";
			continue;
		}
		if(flag2==1)
		{
			sort(a+1,a+n+1,cmp2);
	    	long long sum=0;
	    	for(int i=1;i<=n/2;i++)
	    	{
	    		sum+=a[i].a2;
			}
			cout<<sum<<"\n";
			continue;
		}
		if(flag3==1)
		{
			sort(a+1,a+n+1,cmp3);
	    	long long sum=0;
	    	for(int i=1;i<=n/2;i++)
	    	{
	    		sum+=a[i].a3;
			}
			cout<<sum<<"\n";
			continue;
		}
		if(n==2)
		{
			int maxn=0;
			maxn=max(maxn,a[1].a1+a[2].a2);
			maxn=max(maxn,a[1].a1+a[2].a3);
			maxn=max(maxn,a[1].a2+a[2].a1);
			maxn=max(maxn,a[1].a2+a[2].a3);
			maxn=max(maxn,a[1].a3+a[2].a1);
			maxn=max(maxn,a[1].a3+a[2].a2);
			cout<<maxn<<"\n";
			continue;
		}
		else
		{
			dfs(1,0,0,0,0,n);
			cout<<maxn<<"\n";
			continue; 
		}
	}
	return 0;
}
