#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
long long n,m,a[500100],ans;
void dfs(long long x,long long y)
{
	if(x==m){ ans++;
	dfs(a[y],y+1);}
	if(y>n) return ;
	dfs(x&a[y],y+1);
	dfs(x|a[y],y+1);
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
      scanf("%lld",&a[i]);
      if(a[i]==m) ans++;
    }
    dfs(0,1);
    cout<<ans;
    return 0;	
}
