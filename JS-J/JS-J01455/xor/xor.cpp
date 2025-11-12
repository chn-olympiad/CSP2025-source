#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int n,ka,a[maxn],s[maxn],dp[maxn],c[maxn],flag=1;
/*int lowbit(int x)
{
    return x&(-x);
}
int sum(int x)
{
    int ret=0;
    for(int i=x;i>=0;i-=lowbit(i))
        ret+=c[i];
    return ret;
}
void add(int x,int y)
{
    for(int i=x;i<=n;i+=lowbit(i))
        c[i]+=y;
}*/
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>ka;
    int cnt1=0,cnt2=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=0 && a[i]!=1)
            flag=0;
        if(a[i]==0)
            cnt1++;
        if(a[i]==1)
            cnt2++;
        s[i]=(s[i-1]^a[i]);
    }
    if(flag)
    {
        if(ka==0)
        {
            bool flag1=1;
            cnt1=0;
            for(int i=1;i<=n;i++)
            {
                if(a[i]==0)
                {

                    cnt1++;
                    flag1=1;
                }
                else
                {

                    if(a[i-1]==1 && flag1==1)
                    {
                        cnt1++;
                        flag1=0;
                    }
                    else if(a[i-1]==1 && flag1==0)
                        flag1=1;
                }
            }
            cout<<cnt1;
        }
        else
            cout<<cnt2;
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j>=1;j--)
            {
                int ret2=0;
                for(int k=j;k<=i;k++)
                {
                    for(int t=j;t<=k;t++)
                    {
                        if((s[t-1]^s[k])==ka)
                        {

                            ret2++;
                        }
                    }
                }
                if(ret2>1)
                    break;
                dp[i]=max(dp[j-1]+ret2,dp[i]);
            }
        }
        cout<<dp[n];

    }
    return 0;
}
