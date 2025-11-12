#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5005;
const int mod=998244353;
int n;
int s[N][N];
int a[N];
signed main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    for(int i=2;i<=5000;i++) s[2][i]=s[2][i-1]+(i-1);
    for(int i=3;i<=5000;i++)
        for(int j=i;j<=5000;j++)
            s[i][j]=s[i][j-1]+s[i-1][j-1];
    cin>>n;
    int flag=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) if(a[i]!=1) flag=1;
    if(n==1||n==2)
    {
        cout<<0;
        return 0;
    }
    else if(flag==0)
    {
        int ans=0;
        for(int i=3;i<=n;i++) ans=(ans+s[i][n])%mod;
        cout<<ans%mod;
        return 0;
    }
    else
    {
        if(n==3)
        {
            if(max(a[1],max(a[2],a[3]))*2<(a[1]+a[2]+a[3])) cout<<1;
            else cout<<0;
            return 0;
        }
        else if(n==4)
        {
            int ans=0;
            for(int i=1;i<=n;i++)
            {
                for(int j=i+1;j<=n;j++)
                {
                    for(int k=j+1;k<=n;k++)
                    {
                        if(max(a[i],max(a[j],a[k]))*2<(a[i]+a[j]+a[k])) ans++;
                    }
                }
            }
            if(max(max(a[1],a[2]),max(a[3],a[4]))*2<(a[1]+a[2]+a[3]+a[4])) ans++;
            cout<<ans%mod;
            return 0;
        }
        else if(n==5)
        {
            int ans=0;
            for(int i=1;i<=n;i++)
            {
                for(int j=i+1;j<=n;j++)
                {
                    for(int k=j+1;k<=n;k++)
                    {
                        if(max(a[i],max(a[j],a[k]))*2<(a[i]+a[j]+a[k])) ans++;
                    }
                }
            }
            ans%=mod;
            for(int i=1;i<=n;i++)
            {
                for(int j=i+1;j<=n;j++)
                {
                    for(int k=j+1;k<=n;k++)
                    {
                        for(int p=k+1;p<=n;p++)
                        {
                            if(max(max(a[i],a[p]),max(a[j],a[k]))*2<(a[i]+a[j]+a[k]+a[p])) ans++;
                        }

                    }
                }
            }
            if(max(max(a[1],a[2]),max(a[3],max(a[4],a[5])))*2<(a[1]+a[2]+a[3]+a[4]+a[5])) ans++;
            cout<<ans%mod;
            return 0;
        }
        else if(n==6)
        {
            int ans=0;
            for(int i=1;i<=n;i++)
            {
                for(int j=i+1;j<=n;j++)
                {
                    for(int k=j+1;k<=n;k++)
                    {
                        if(max(a[i],max(a[j],a[k]))*2<(a[i]+a[j]+a[k])) ans++;
                    }
                }
            }
            ans%=mod;
            for(int i=1;i<=n;i++)
            {
                for(int j=i+1;j<=n;j++)
                {
                    for(int k=j+1;k<=n;k++)
                    {
                        for(int p=k+1;p<=n;p++)
                        {
                            if(max(max(a[i],a[p]),max(a[j],a[k]))*2<(a[i]+a[j]+a[k]+a[p])) ans++;
                        }

                    }
                }
            }
            ans%=mod;
            for(int i=1;i<=n;i++)
            {
                for(int j=i+1;j<=n;j++)
                {
                    for(int k=j+1;k<=n;k++)
                    {
                        for(int p=k+1;p<=n;p++)
                        {
                            for(int o=p+1;o<=n;o++)
                            {
                                if(max(max(a[i],a[p]),max(a[j],max(a[k],a[o])))*2<(a[i]+a[j]+a[k]+a[p]+a[o])) ans++;
                            }

                        }

                    }
                }
            }
            if(max(max(a[1],a[2]),max(max(a[3],a[6]),max(a[4],a[5])))*2<(a[1]+a[2]+a[3]+a[4]+a[5]+a[6])) ans++;
            cout<<ans%mod;
            return 0;
        }
        else if(n==7)
        {
            int ans=0;
            for(int i=1;i<=n;i++)
            {
                for(int j=i+1;j<=n;j++)
                {
                    for(int k=j+1;k<=n;k++)
                    {
                        if(max(a[i],max(a[j],a[k]))*2<(a[i]+a[j]+a[k])) ans++;
                    }
                }
            }
            ans%=mod;
            for(int i=1;i<=n;i++)
            {
                for(int j=i+1;j<=n;j++)
                {
                    for(int k=j+1;k<=n;k++)
                    {
                        for(int p=k+1;p<=n;p++)
                        {
                            if(max(max(a[i],a[p]),max(a[j],a[k]))*2<(a[i]+a[j]+a[k]+a[p])) ans++;
                        }

                    }
                }
            }
            ans%=mod;
            for(int i=1;i<=n;i++)
            {
                for(int j=i+1;j<=n;j++)
                {
                    for(int k=j+1;k<=n;k++)
                    {
                        for(int p=k+1;p<=n;p++)
                        {
                            for(int o=p+1;o<=n;o++)
                            {
                                if(max(max(a[i],a[p]),max(a[j],max(a[k],a[o])))*2<(a[i]+a[j]+a[k]+a[p]+a[o])) ans++;
                            }

                        }

                    }
                }
            }
            ans%=mod;
            for(int i=1;i<=n;i++)
            {
                for(int j=i+1;j<=n;j++)
                {
                    for(int k=j+1;k<=n;k++)
                    {
                        for(int p=k+1;p<=n;p++)
                        {
                            for(int o=p+1;o<=n;o++)
                            {
                                for(int u=o+1;u<=n;u++)
                                {
                                    if(max(max(max(a[i],a[u]),a[p]),max(a[j],max(a[k],a[o])))*2<(a[i]+a[j]+a[k]+a[p]+a[o]+a[u])) ans++;
                                }

                            }

                        }

                    }
                }
            }
            if(max(max(max(a[1],a[7]),a[2]),max(max(a[3],a[6]),max(a[4],a[5])))*2<(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7])) ans++;
            cout<<ans%mod;
            return 0;
        }
        else if(n==8)
        {
            int ans=0;
            for(int i=1;i<=n;i++)
            {
                for(int j=i+1;j<=n;j++)
                {
                    for(int k=j+1;k<=n;k++)
                    {
                        if(max(a[i],max(a[j],a[k]))*2<(a[i]+a[j]+a[k])) ans++;
                    }
                }
            }
            ans%=mod;
            for(int i=1;i<=n;i++)
            {
                for(int j=i+1;j<=n;j++)
                {
                    for(int k=j+1;k<=n;k++)
                    {
                        for(int p=k+1;p<=n;p++)
                        {
                            if(max(max(a[i],a[p]),max(a[j],a[k]))*2<(a[i]+a[j]+a[k]+a[p])) ans++;
                        }

                    }
                }
            }
            ans%=mod;
            for(int i=1;i<=n;i++)
            {
                for(int j=i+1;j<=n;j++)
                {
                    for(int k=j+1;k<=n;k++)
                    {
                        for(int p=k+1;p<=n;p++)
                        {
                            for(int o=p+1;o<=n;o++)
                            {
                                if(max(max(a[i],a[p]),max(a[j],max(a[k],a[o])))*2<(a[i]+a[j]+a[k]+a[p]+a[o])) ans++;
                            }

                        }

                    }
                }
            }
            ans%=mod;
            for(int i=1;i<=n;i++)
            {
                for(int j=i+1;j<=n;j++)
                {
                    for(int k=j+1;k<=n;k++)
                    {
                        for(int p=k+1;p<=n;p++)
                        {
                            for(int o=p+1;o<=n;o++)
                            {
                                for(int u=o+1;u<=n;u++)
                                {
                                    if(max(max(max(a[i],a[u]),a[p]),max(a[j],max(a[k],a[o])))*2<(a[i]+a[j]+a[k]+a[p]+a[o]+a[u])) ans++;
                                }

                            }

                        }

                    }
                }
            }
            ans%=mod;
            for(int i=1;i<=n;i++)
            {
                for(int j=i+1;j<=n;j++)
                {
                    for(int k=j+1;k<=n;k++)
                    {
                        for(int p=k+1;p<=n;p++)
                        {
                            for(int o=p+1;o<=n;o++)
                            {
                                for(int u=o+1;u<=n;u++)
                                {
                                    for(int y=u+1;y<=n;y++)
                                    {
                                        if(max(max(max(a[i],a[u]),max(a[p],a[y])),max(a[j],max(a[k],a[o])))*2<(a[i]+a[j]+a[k]+a[p]+a[o]+a[u]+a[y])) ans++;
                                    }

                                }

                            }

                        }

                    }
                }
            }
            if(max(max(max(a[1],a[7]),max(a[2],a[8])),max(max(a[3],a[6]),max(a[4],a[5])))*2<(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8])) ans++;
            cout<<ans%mod;
            return 0;
        }
        else if(n==9)
        {
            int ans=0;
            for(int i=1;i<=n;i++)
            {
                for(int j=i+1;j<=n;j++)
                {
                    for(int k=j+1;k<=n;k++)
                    {
                        if(max(a[i],max(a[j],a[k]))*2<(a[i]+a[j]+a[k])) ans++;
                    }
                }
            }
            ans%=mod;
            for(int i=1;i<=n;i++)
            {
                for(int j=i+1;j<=n;j++)
                {
                    for(int k=j+1;k<=n;k++)
                    {
                        for(int p=k+1;p<=n;p++)
                        {
                            if(max(max(a[i],a[p]),max(a[j],a[k]))*2<(a[i]+a[j]+a[k]+a[p])) ans++;
                        }

                    }
                }
            }
            ans%=mod;
            for(int i=1;i<=n;i++)
            {
                for(int j=i+1;j<=n;j++)
                {
                    for(int k=j+1;k<=n;k++)
                    {
                        for(int p=k+1;p<=n;p++)
                        {
                            for(int o=p+1;o<=n;o++)
                            {
                                if(max(max(a[i],a[p]),max(a[j],max(a[k],a[o])))*2<(a[i]+a[j]+a[k]+a[p]+a[o])) ans++;
                            }

                        }

                    }
                }
            }
            ans%=mod;
            for(int i=1;i<=n;i++)
            {
                for(int j=i+1;j<=n;j++)
                {
                    for(int k=j+1;k<=n;k++)
                    {
                        for(int p=k+1;p<=n;p++)
                        {
                            for(int o=p+1;o<=n;o++)
                            {
                                for(int u=o+1;u<=n;u++)
                                {
                                    if(max(max(max(a[i],a[u]),a[p]),max(a[j],max(a[k],a[o])))*2<(a[i]+a[j]+a[k]+a[p]+a[o]+a[u])) ans++;
                                }

                            }

                        }

                    }
                }
            }
            ans%=mod;
            for(int i=1;i<=n;i++)
            {
                for(int j=i+1;j<=n;j++)
                {
                    for(int k=j+1;k<=n;k++)
                    {
                        for(int p=k+1;p<=n;p++)
                        {
                            for(int o=p+1;o<=n;o++)
                            {
                                for(int u=o+1;u<=n;u++)
                                {
                                    for(int y=u+1;y<=n;y++)
                                    {
                                        if(max(max(max(a[i],a[u]),max(a[p],a[y])),max(a[j],max(a[k],a[o])))*2<(a[i]+a[j]+a[k]+a[p]+a[o]+a[u]+a[y])) ans++;
                                    }

                                }

                            }

                        }

                    }
                }
            }
            ans%=mod;
            for(int i=1;i<=n;i++)
            {
                for(int j=i+1;j<=n;j++)
                {
                    for(int k=j+1;k<=n;k++)
                    {
                        for(int p=k+1;p<=n;p++)
                        {
                            for(int o=p+1;o<=n;o++)
                            {
                                for(int u=o+1;u<=n;u++)
                                {
                                    for(int y=u+1;y<=n;y++)
                                    {
                                        for(int t=y+1;t<=n;t++)
                                        {
                                            if(max(max(max(max(a[i],a[t]),a[u]),max(a[p],a[y])),max(a[j],max(a[k],a[o])))*2<(a[i]+a[j]+a[k]+a[p]+a[o]+a[u]+a[y]+a[t])) ans++;
                                        }

                                    }

                                }

                            }

                        }

                    }
                }
            }
            if(max(max(max(max(a[1],a[9]),a[7]),max(a[2],a[8])),max(max(a[3],a[6]),max(a[4],a[5])))*2<(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9])) ans++;
            cout<<ans%mod;
            return 0;
        }
    }
    return 0;

}
