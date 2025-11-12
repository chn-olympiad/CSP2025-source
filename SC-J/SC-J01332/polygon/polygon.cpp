#include<iostream>
#include<cstdio> 
#include<algorithm> 
using namespace std;
int n;
int a[5005];
int ans;
void dfs(int x,int maxn,int num,int m)
{
	if(x==n)
	{
		if(num>maxn*2&&m>=3)
		{
			ans++;
		}
	}
	else
	{
		dfs(x+1,max(maxn,a[x+1]),num+a[x+1],m+1);
		dfs(x,maxn,num,m);
	}
 } 
int main()
{
	freopen("polygon.in","r",stdin); 
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
	}
    if(n<=3)
    {
        if(a[1]+a[2]+a[3]>2*a[1]||
        a[1]+a[2]+a[3]>2*a[2]||
        a[1]+a[2]+a[3]>2*a[3])
        {
		 cout<<1;
        return 0;
		}
       
        else
        {
        cout<<0;
        return 0;
        }
    }
	dfs(1,a[1],a[1],1);
	dfs(0,0,0,0);
	cout<<ans%998244353;
	return 0;
}