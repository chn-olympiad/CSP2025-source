#include<bits/stdc++.h>
using namespace std;
int T,n,a[100005][5],ans,t[5],sum2,sum3,b[100005],c[100005],d[100005];
void dfs(int step,int sum)
{
    if(step>n)
    {
        ans=max(ans,sum);
        return;
    }
    for(int i=1;i<=3;i++)
    {
        if(t[i]<n/2)
        {
            t[i]++;
            dfs(step+1,sum+a[step][i]);
            t[i]--;
        }
    }
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>n;
        memset(t,0,sizeof(t));
        ans=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            sum2+=a[i][2],b[i]=a[i][1];
            sum3+=a[i][3],c[i]=a[i][2];
        }
        if(n<=30)
        {
            dfs(1,0);
            cout<<ans<<'\n';
        }
        else if(sum2==0&&sum3==0)
        {
            sort(b+1,b+n+1,greater<int>());
            for(int i=1;i<=n/2;i++)
            {
                ans+=b[i];
            }
            cout<<ans<<'\n';
        }
        else if(sum3==0)
        {
            for(int i=1;i<=n;i++)
            {
                c[i]=a[i][1]-a[i][2];
                d[i]=c[i];
            }
            sort(c+1,c+n+1,greater<int>());
            int op=c[n/2],kh=0;
            for(int i=1;i<=n;i++)
            {
                if(d[i]>op)
                {
                    ans+=a[i][1];
                    kh++;
                }
                else if(d[i]==op)
                {
                    (kh<n/2?ans+=a[i][1],kh++:ans+=a[i][2]);
                }
                else
                {
                    ans+=a[i][2];
                }
            }
            cout<<ans<<'\n';
        }
    }
    return 0;
}
