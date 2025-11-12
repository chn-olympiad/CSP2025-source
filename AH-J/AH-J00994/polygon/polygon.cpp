#include <bits/stdc++.h>
using namespace std;
int n,max,sum,ans,a[5010];
bool b[5010];
void dfs(int dep,int t,int m)
{
	if(dep>m)
	{	
		if(sum>2*a[t-1])
		    ans++;
		return;
	}
	for(int i=t;i<=n;i++)
	{
		if(!b[i])
		{
			sum+=a[i];
			b[i]=true;
			dfs(dep+1,i+1,m);
			b[i]=false;
			sum-=a[i];
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
	for(int i=3;i<=n;i++)
	    dfs(1,1,i);
	cout<<ans<<endl;
    return 0;
}
