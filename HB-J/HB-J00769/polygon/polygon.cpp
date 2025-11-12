#include <bits/stdc++.h>
using namespace std;
const int P=998244353;
int a[5005]={0},Count=0;
bool aa[5005]={0};
int n;
void dfs(int x)
{
    if(x==n+1)
    {
        int sum=0,mx=-1,cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(aa[i]==1)
            {
                cnt++;
                sum+=a[i];
                if(a[i]>mx)
                {
                    mx=a[i];
                }
            }
        }
        if(cnt<3)
        {
            return;
        }
        else if(sum>mx*2)
        {
            Count++;
            return;
        }
        else
        {
            return;
        }
    }
    else
    {
        aa[x]=1;
        dfs(x+1);
        aa[x]=0;
        dfs(x+1);
    }
};
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    bool flag=1;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=1)
        {
            flag=0;
        }
    }
    if(n==3)
    {
        if(max(a[1],max(a[2],a[3]))*2<a[1]+a[2]+a[3])
        {
            cout<<1;
        }
        else
        {
            cout<<0;
        }
    }
    else if(flag==1)
    {
        long long ans=0;
        for(int i=3;i<=n;i++)
        {
            long long now1=1;
            for(int j=n;j>=n-i+1;j--)
            {
                now1*=j;
                now1%=P;
            }
            long long now2=1;
            for(int j=2;j<=i;j++)
            {
                now2*=j;
                now2%=P;
            }
            ans+=(now1/now2);
            ans%=P;
        }
        cout<<ans;
    }
    else
    {
        dfs(1);
        cout<<Count;
    }
    return 0;
}//Score++40 Score--0
