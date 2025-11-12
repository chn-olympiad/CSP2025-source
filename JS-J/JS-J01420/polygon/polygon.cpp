#include <bits/stdc++.h>
using namespace std;
long long a[100010];
long long mod=998244353;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    long long n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n<=2)
    {
       cout<<"0";
       return 0;
    }
    if(n==3)
    {
        if(2*max(a[1],max(a[2],a[3]))>=a[1]+a[2]+a[3])
        {
            cout<<"0";
        }
        else cout<<"1";
        return 0;
    }
    else if(n<=10)
    {

        long long ret=0;
        for(long long s=1;s<=10;s++)
        {
            for(long long b=s+1;b<=10;b++)
            {
                for(long long c=b+1;c<=10;c++)
                {
                    if(max(a[s],max(a[b],a[c]))*2<a[s]+a[b]+a[c])
                    {
                        ret++;
                    }
                }
            }
        }
            ret%=mod;
        for(long long s=1;s<=10;s++)
        {
            for(long long b=s+1;b<=10;b++)
            {
                for(long long c=b+1;c<=10;c++)
                {
                    for(long long d=c+1;d<=10;d++)
                    {
                        if(max(a[s],max(a[b],max(a[c],a[d])))*2<a[s]+a[b]+a[c]+a[d] && a[s]!=0 && a[b]!=0 && a[c]!=0 && a[d]!=0)
                        {
                            ret++;
                        }
                    }
                }
            }
        }
        ret%=mod;
        for(long long s=1;s<=10;s++)for(long long b=s+1;b<=10;b++)for(long long c=b+1;c<=10;c++)for(long long d=c+1;d<=10;d++)for(long long e=d+1;e<=10;e++)
        if(max(a[s],max(a[b],max(a[c],max(a[d],a[e]))))*2<a[s]+a[b]+a[c]+a[d]+a[e] && a[s]!=0 && a[b]!=0 && a[c]!=0 && a[d]!=0 && a[e]!=0)
        ret++;
        ret%=mod;
        for(long long s=1;s<=10;s++)
        {
            for(long long b=s+1;b<=10;b++)
            {
                for(long long c=b+1;c<=10;c++)
                {
                    for(long long d=c+1;d<=10;d++)
                    {
                        for(long long e=d+1;e<=10;e++)
                        {
                            for(long long f=e+1;f<=10;f++)
                            {
                                if(max(a[s],max(a[b],max(a[c],max(a[d],max(a[e],a[f])))))*2<a[s]+a[b]+a[c]+a[d]+a[e] && a[s]!=0 && a[b]!=0 && a[c]!=0 && a[d]!=0 && a[e]!=0 && a[f]!=0)
                                {
                                    ret++;
                                }
                            }
                        }
                    }
                }
            }
        }
        ret%=mod;
        for(long long s=1;s<=10;s++)
        {
            for(long long b=s+1;b<=10;b++)
            {
                for(long long c=b+1;c<=10;c++)
                {
                    for(long long d=c+1;d<=10;d++)
                    {
                        for(long long e=d+1;e<=10;e++)
                        {
                            for(long long f=e+1;f<=10;f++)
                            {
                                for(long long g=f+1;g<=10;g++)
                                {
                                    if(max(a[s],max(a[b],max(a[c],max(a[d],max(a[e],max(a[f],a[g]))))))*2<a[s]+a[b]+a[c]+a[d]+a[e]+a[g] && a[s]!=0 && a[b]!=0 && a[c]!=0 && a[d]!=0 && a[e]!=0 && a[f]!=0 && a[g]!=0)
                                    {
                                        ret++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        ret%=mod;
        for(long long s=1;s<=10;s++)
        {
            for(long long b=s+1;b<=10;b++)
            {
                for(long long c=b+1;c<=10;c++)
                {
                    for(long long d=c+1;d<=10;d++)
                    {
                        for(long long e=d+1;e<=10;e++)
                        {
                            for(long long f=e+1;f<=10;f++)
                            {
                                for(long long g=f+1;g<=10;g++)
                                {
                                    for(long long h=g+1;h<=10;h++)
                                    {
                                        if(max(a[s],max(a[b],max(a[c],max(a[d],max(a[e],max(a[f],max(a[g],a[h])))))))*2<a[s]+a[b]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h] && a[s]!=0 && a[b]!=0 && a[c]!=0 && a[d]!=0 && a[e]!=0 && a[f]!=0 && a[g]!=0 && a[h]!=0)
                                        {
                                            ret++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        ret%=mod;
        for(long long s=1;s<=10;s++)
        {
            for(long long b=s+1;b<=10;b++)
            {
                for(long long c=b+1;c<=10;c++)
                {
                    for(long long d=c+1;d<=10;d++)
                    {
                        for(long long e=d+1;e<=10;e++)
                        {
                            for(long long f=e+1;f<=10;f++)
                            {
                                for(long long g=f+1;g<=10;g++)
                                {
                                    for(long long h=g+1;h<=10;h++)
                                    {
                                        for(long long i=h+1;i<=10;i++)
                                        {
                                            if(max(a[s],max(a[b],max(a[c],max(a[d],max(a[e],max(a[f],max(a[g],max(a[h],a[i]))))))))*2<a[s]+a[b]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h]+a[i] && a[s]!=0 && a[b]!=0 && a[c]!=0 && a[d]!=0 && a[e]!=0 && a[f]!=0 && a[g]!=0 && a[h]!=0 && a[i]!=0)
                                            {
                                                ret++;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        ret%=mod;
        for(long long s=1;s<=10;s++)
        {
            for(long long b=s+1;b<=10;b++)
            {
                for(long long c=b+1;c<=10;c++)
                {
                    for(long long d=c+1;d<=10;d++)
                    {
                        for(long long e=d+1;e<=10;e++)
                        {
                            for(long long f=e+1;f<=10;f++)
                            {
                                for(long long g=f+1;g<=10;g++)
                                {
                                    for(long long h=g+1;h<=10;h++)
                                    {
                                        for(long long i=h+1;i<=10;i++)
                                        {
                                            for(long long j=i+1;j<=10;j++)
                                            {
                                                if(max(a[s],max(a[b],max(a[c],max(a[d],max(a[e],max(a[f],max(a[g],max(a[h],max(a[i],a[j])))))))))*2<a[s]+a[b]+a[c]+a[d]+a[e]+a[g]+a[h]+a[i]+a[j] && a[s]!=0 && a[b]!=0 && a[c]!=0 && a[d]!=0 && a[e]!=0 && a[f]!=0 && a[g]!=0 && a[h]!=0 && a[i]!=0 && a[j]!=0)
                                                {
                                                    ret++;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        ret%=mod;
        cout<<ret;
    }
    if(n>=11)
    {
        long long cnt=0;
       for(long long i=3;i<=n;i++)
       {
           long long x=min(i,n-i);
           long long ret=1;
           for(int i=0;i<x;i++)
           {
               ret*=(n-i)/(i+1);
               ret%=mod;
           }
           cnt+=ret;
           cnt%=mod;
       }
       cout<<cnt;
       return 0;
    }
    return 0;
}
