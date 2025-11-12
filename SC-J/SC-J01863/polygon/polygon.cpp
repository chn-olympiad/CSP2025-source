#include <bits/stdc++.h>
using namespace std;
const int Mod=998244353;
bool flag=true;
int n,ans=0;
int a[5005],plan[5005];
bool chk(int cur)
{
    if (cur<3)
        return false;
    int maxn=0,sum=0;
    for (int i=1;i<=cur;i++)
    {
        maxn=max(maxn,plan[i]);
        sum+=plan[i];
    }
    return maxn*2<sum;
}
void dfs(int step,int cur)
{
    if (step==n+1)
    {
        if (chk(cur))
            ans=(ans+1)%Mod;
        return;
    }
    dfs(step+1,cur);
    plan[++cur]=a[step];
    dfs(step+1,cur);
    return;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        if (a[i]!=1)
        	flag=false;
    }
    if (flag)
    {
    	for (int i=3;i<=n;i++)
    	{
    		long long mul_1=1,mul_2=1;
			int tmp_1=n,tmp_2=i;
    		for (int j=1;j<=i;j++)
    		{
    			mul_1*=tmp_1;
    			mul_2*=tmp_2;
    			tmp_1--;
    			tmp_2--;
			}
			ans=(ans+mul_1/mul_2)%Mod;
    	}
    	cout<<ans;
    	return 0;
	}
    dfs(1,0);
    cout<<ans;
    return 0;
}