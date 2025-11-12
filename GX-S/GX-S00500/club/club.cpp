#include<bits/stdc++.h>
using namespace std;
long long ITF=1e14;
long long n,a1,a2,a3,ans,sum[100005],d1[100005][2],a[100005][2],c[4];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,i,j;
    cin>>t;
    while(t--)
    {
        priority_queue<long long>dp[4];
        ans=0;
        cin>>n;
        c[1]=c[2]=c[3]=0;
        for(i=1;i<=n;i++)
        {
            cin>>a1>>a2>>a3;
            if(max(a1,max(a2,a3))==a1)
            {
                d1[i][0]=1;
                a[i][0]=a1;
            }
            else if(max(a1,max(a2,a3))==a2)
            {
                d1[i][0]=2;
                a[i][0]=a2;
            }
            else if(max(a1,max(a2,a3))==a3)
            {
                d1[i][0]=3;
                a[i][0]=a3;
            }
            if(min(a1,min(a2,a3))==a1)
            {
                if(d1[i][0]==2)
                {
                    d1[i][1]=3;
                    a[i][1]=a3;
                }
                else
                {
                    d1[i][1]=2;
                    a[i][1]=a2;
                }
            }
            else if(min(a1,min(a2,a3))==a2)
            {
                if(d1[i][0]==1)
                {
                    d1[i][1]=3;
                    a[i][1]=a3;
                }
                else
                {
                    d1[i][1]=1;
                    a[i][1]=a1;
                }
            }
            else if(min(a1,min(a2,a3))==a3)
            {
                if(d1[i][0]==2)
                {
                    d1[i][1]=1;
                    a[i][1]=a1;
                }
                else
                {
                    d1[i][1]=2;
                    a[i][1]=a2;
                }
            }
            sum[i]=a[i][0]-a[i][1];
        }
        for(i=1;i<=n;i++)
        {
            if(c[d1[i][0]]<n/2)
            {
                c[d1[i][0]]++;
                dp[d1[i][0]].push(ITF-sum[i]);
                ans+=a[i][0];
                continue;
            }
            else if(c[d1[i][0]]>=n/2)
            {
                long long x=-5;
                x=-1;
                for(j=1;j<=i;j++)
                {
                    if(d1[j][0]==d1[i][0])
                    {
                        if(ITF-sum[j]==dp[d1[i][0]].top())
                        {
                            x=j;
                            break;
                        }
                    }
                }
                if(a[x][0]+a[i][1]>=a[x][1]+a[i][0])
                {
                    ans+=a[i][1];
                }
                else
                {
                    ans+=a[i][0]-a[x][0]+a[x][1];
                    dp[d1[i][0]].push(ITF-sum[i]);
                    dp[d1[i][0]].pop();
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

