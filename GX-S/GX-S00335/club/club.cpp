#include <bits/stdc++.h>
using namespace std;
int cmp(long long a,long long b)
{
    return a>b;
}
int cmp2(long long a,long long b)
{
    return a<b;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        long long n;
        long long x[100005],y[100005],z[100005];
        cin>>n;
        long long ans=0;
        bool er=true,san=true;
        for(int i=1;i<=n;i++)
        {
            cin>>x[i]>>y[i]>>z[i];
            if(y[i]!=0)
            {
                er=false;
            }
            if(z[i]!=0)
            {
                san=false;
            }
        }
        if(er&&san)
        {
            sort(x+1,x+n+1,cmp);
            for(int i=1;i<=n/2;i++)
            {
                ans+=x[i];
            }
            cout<<ans<<endl;
        }
        if(!er &&san)
        {
            long long yishu=0,ershu=0;
            for(int i=1;i<=n;i++)
            {
                if(yishu==n/2)
                {
                    ans+=y[i];
                    ershu++;
                    continue;
                }
                if(ershu==n/2)
                {
                    ans+=x[i];
                    yishu++;
                    continue;
                }
                if(x[i]>=y[i])
                {
                    yishu++;
                    ans+=x[i];
                }
                if(y[i]>x[i])
                {
                    ershu++;
                    ans+=y[i];
                }
            }
            cout<<ans<<endl;
        }
        if(!er && !san)
        {
            long long yishu=0,ershu=0,sanshu=0;
            for(int i=1;i<=n;i++){
                if(yishu==n/2)
                {
                    if(ershu==n/2)
                    {
                        sanshu++;
                        ans+=z[i];
                    }
                    else{
                        if(y[i]>=z[i])
                        {
                            ershu++;
                            ans+=y[i];
                        }
                        else{
                            sanshu++;
                            ans+=z[i];
                        }
                    }
                    continue;
                }
                if(ershu==n/2)
                {
                    if(yishu==n/2)
                    {
                        sanshu++;
                        ans+=x[i];
                    }
                    else{
                        if(x[i]>=z[i])
                        {
                            yishu++;
                            ans+=x[i];
                        }
                        else{
                            sanshu++;
                            ans+=z[i];
                        }
                    }
                    continue;
                }
                if(sanshu==n/2)
                {
                    if(ershu==n/2)
                    {
                        yishu++;
                        ans+=x[i];
                    }
                    else{
                        if(x[i]>=y[i])
                        {
                            yishu++;
                            ans+=x[i];
                        }
                        else{
                            ershu++;
                            ans+=y[i];
                        }
                    }
                    continue;
                }
                if(x[i]>=y[i]&&x[i]>=z[i])
                {
                    ans+=x[i];
                    yishu++;
                }
                else if(y[i]>=x[i]&&y[i]>=z[i])
                {
                    ershu++;
                    ans+=y[i];
                }
                else if(z[i]>=x[i]&&z[i]>=y[i])
                {
                    sanshu++;
                    ans+=z[i];
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
