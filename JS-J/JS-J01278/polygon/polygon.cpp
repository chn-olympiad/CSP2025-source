#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n,m = 0,a[5010];
    cin >> n;
    for(long long i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for(long long i = 1;i <= n;i++)
    {
        for(long long j = i+1;j <= n;j++)
        {
            for(long long k = j+1;k <= n;k++)
            {
                if(a[i]+a[j]+a[k]>a[k]*2)m++;
                for(long long x = k+1;x <= n;x++)
                {
                    if(a[i]+a[j]+a[k]+a[x]>2*a[x])m++;
                    for(long long y = x+1;y <= n;y++)
                    {
                        if(a[i]+a[j]+a[k]+a[x]+a[y]>2*a[y])m++;
                        for(long long z = y+1;z <= n;z++)
                        {
                            if(a[i]+a[j]+a[k]+a[x]+a[y]+a[z]>2*a[z])m++;
                            for(long long v = z+1;v <= n;v++)
                            {
                                if(a[i]+a[j]+a[k]+a[x]+a[y]+a[z]+a[v]>2*a[v])m++;
                                for(long long u = v+1;u <= n;u++)
                                {
                                    if(a[i]+a[j]+a[k]+a[x]+a[y]+a[z]+a[v]+a[u]>2*a[u])m++;
                                    for(long long w = u+1;w <= n;w++)
                                    {
                                        if(a[i]+a[j]+a[k]+a[x]+a[y]+a[z]+a[v]+a[u]+a[w]>2*a[w])m++;
                                        for(long long s = w+1;s <= n;s++)
                                        {
                                            if(a[i]+a[j]+a[k]+a[x]+a[y]+a[z]+a[v]+a[u]+a[w]+a[s]>2*a[s])m++;
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
    cout << m;
    return 0;
}
