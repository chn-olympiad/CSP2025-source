#include<bits/stdc++.h>
#define int long long
#define sc scanf
#define pr printf
#define fr freopen("polygon.in","r",stdin);freopen("polygon.out","w",stdout);
#define w while
#define f(i,x,n,y) for(int i=x;i<=n;i+=y)
#define st string
using namespace std;
struct fu{
	int vis,si;
}a[64596];
int sum,n,b[4378464],k;
bool cmp(fu a,fu b)
{
	return a.si<b.si;
}
void dfs(int s,int start)
{
	f(i,start,n,1)
	{
		if(!a[i].vis)
		{
			if(s==1)
			{
				if(a[i].si<b[k])
				{
					sum++;
					sum%=998244353;
				}
			}
			else
			{
				b[k]+=a[i].si;
				a[i].vis=1;
				dfs(s-1,i);
				b[k]-=a[i].si;
				a[i].vis=0;	
			}				
		}		
	}	
}
signed main()
{
	fr
	cin>>n;
	f(i,1,n,1)
	{
		sc("%lld",&a[i].si);
	}
	sort(a+1,a+1+n,cmp);
	f(i,3,n,1)
	{
		k++;
		dfs(i,1);
	}
	cout<<sum;
	return 0;
}

