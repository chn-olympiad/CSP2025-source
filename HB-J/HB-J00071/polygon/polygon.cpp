#include<bits/stdc++.h>
using namespace std;
int n;
int l[5000];
int a[5000];
int sum,maxn,ans=0,i;
void dfs(int step,int now)
{
    sum+=a[now];
    //cout<<"a[now]:"<<a[now]<<endl;
    maxn=0;
    if (step==i)
    {
        for (int k=0;k<n;k++)
        {
            maxn=max(maxn,a[k]);
        }
        if (sum>2*maxn)
        {
            ans++;
        }
        sum-=a[now];
        return ;
    }
    //return rules
    for (int j=now+1;j<n;j++)
    {
        dfs(step+1,j);
        //cout<<"sum:"<<sum<<endl;
    }
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    //cin>>n;
    for (int i=0;i<n;i++)
    {
        //cin>>l[i];
    }
    for (i=3;i<=n;i++)
    {
        sum=0;
        dfs(0,1);
    }
    cout<<ans;
    return 0;
}
