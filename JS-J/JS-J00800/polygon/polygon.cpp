#include <bits/stdc++.h>
using namespace std;
int a[5010];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)
    {
        scanf("%d",&a[i]);
    }
    long long ret = 0;
    for(int k = 3;k <= n;k++)
    {
        if(k == 3)
        {
            for(int i = 1;i <= n;i++)
            {
                for(int j = i + 1;j <= n;j++)
                {
                    for(int i1 = j + 1;i1 <= n;i1++)
                    {
                        long long mx = max(a[i],max(a[i1],a[j]));
                        if(1LL * a[i] + a[j] + a[i1] > mx * 2)
                        {
                            ret++;
                        }
                    }
                }
            }
        }
        else if(k == 4)
        {
            for(int i = 1;i <= n;i++)
            {
                for(int j = i + 1;j <= n;j++)
                {
                    for(int i1 = j + 1;i1 <= n;i1++)
                    {
                        for(int j1 = i1 + 1;j1 <= n;j1++)
                        {
                            long long mx = max(a[i],max(a[i1],max(a[j],a[j1])));
                            if(1LL * a[i] + a[j] + a[i1] + a[j1] > mx * 2)
                            {
                                ret++;
                            }
                        }
                    }
                }
            }
        }
        else if(k == 5)
        {
            for(int i = 1;i <= n;i++)
            {
                for(int j = i + 1;j <= n;j++)
                {
                    for(int i1 = j + 1;i1 <= n;i1++)
                    {
                        for(int j1 = i1 + 1;j1 <= n;j1++)
                        {
                            for(int i2 = j1 + 1;i2 <= n;i2++)
                            {
                                long long mx = max(a[i],max(a[i1],max(a[j],max(a[j1],a[i2]))));
                                if(1LL * a[i] + a[j] + a[i1] + a[j1] + a[i2] > mx * 2)
                                {
                                    ret++;
                                }
                            }
                        }
                    }
                }
            }
        }
        else if(k == 6)
        {
            for(int i = 1;i <= n;i++)
            {
                for(int j = i + 1;j <= n;j++)
                {
                    for(int i1 = j + 1;i1 <= n;i1++)
                    {
                        for(int j1 = i1 + 1;j1 <= n;j1++)
                        {
                            for(int i2 = j1 + 1;i2 <= n;i2++)
                            {
                                for(int j2 = i2 + 1;j2 <= n;j2++)
                                {
                                    long long mx = max(a[i],max(a[i1],max(a[j],max(a[j1],max(a[i2],a[j2])))));
                                    if(1LL * a[i] + a[j] + a[i1] + a[j1] + a[i2] + a[j2] > mx * 2)
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
        else if(k == 7)
        {
            for(int i = 1;i <= n;i++)
            {
                for(int j = i + 1;j <= n;j++)
                {
                    for(int i1 = j + 1;i1 <= n;i1++)
                    {
                        for(int j1 = i1 + 1;j1 <= n;j1++)
                        {
                            for(int i2 = j1 + 1;i2 <= n;i2++)
                            {
                                for(int j2 = i2 + 1;j2 <= n;j2++)
                                {
                                    for(int i3 = j2 + 1;i3 <= n;i3++)
                                    {
                                        long long mx = max(a[i],max(a[i1],max(a[j],max(a[j1],max(a[i2],max(a[j2],a[i3]))))));
                                        if(1LL * a[i] + a[j] + a[i1] + a[j1] + a[i2] + a[j2] + a[i3] > mx * 2)
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
        else if(k == 8)
        {
            for(int i = 1;i <= n;i++)
            {
                for(int j = i + 1;j <= n;j++)
                {
                    for(int i1 = j + 1;i1 <= n;i1++)
                    {
                        for(int j1 = i1 + 1;j1 <= n;j1++)
                        {
                            for(int i2 = j1 + 1;i2 <= n;i2++)
                            {
                                for(int j2 = i2 + 1;j2 <= n;j2++)
                                {
                                    for(int i3 = j2 + 1;i3 <= n;i3++)
                                    {
                                        for(int j3 = i3 + 1;j3 <= n;j3++)
                                        {
                                            long long mx = max(a[i],max(a[i1],max(a[j],max(a[j1],max(a[i2],max(a[j2],max(a[i3],a[j3])))))));
                                            if(1LL * a[i] + a[j] + a[i1] + a[j1] + a[i2] + a[j2] + a[i3] + a[j3] > mx * 2)
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
        else if(k == 9)
        {
            for(int i = 1;i <= n;i++)
            {
                for(int j = i + 1;j <= n;j++)
                {
                    for(int i1 = j + 1;i1 <= n;i1++)
                    {
                        for(int j1 = i1 + 1;j1 <= n;j1++)
                        {
                            for(int i2 = j1 + 1;i2 <= n;i2++)
                            {
                                for(int j2 = i2 + 1;j2 <= n;j2++)
                                {
                                    for(int i3 = j2 + 1;i3 <= n;i3++)
                                    {
                                        for(int j3 = i3 + 1;j3 <= n;j3++)
                                        {
                                            for(int i4 = j3 + 1;i4 <= n;i4++)
                                            {
                                                long long mx = max(a[i],max(a[i1],max(a[j],max(a[j1],max(a[i2],max(a[j2],max(a[i3],max(a[j3],a[i4]))))))));
                                                if(1LL * a[i] + a[j] + a[i1] + a[j1] + a[i2] + a[j2] + a[i3] + a[j3] + a[i4] > mx * 2)
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
        else if(k == 10)
        {
            for(int i = 1;i <= n;i++)
            {
                for(int j = i + 1;j <= n;j++)
                {
                    for(int i1 = j + 1;i1 <= n;i1++)
                    {
                        for(int j1 = i1 + 1;j1 <= n;j1++)
                        {
                            for(int i2 = j1 + 1;i2 <= n;i2++)
                            {
                                for(int j2 = i2 + 1;j2 <= n;j2++)
                                {
                                    for(int i3 = j2 + 1;i3 <= n;i3++)
                                    {
                                        for(int j3 = i3 + 1;j3 <= n;j3++)
                                        {
                                            for(int i4 = j3 + 1;i4 <= n;i4++)
                                            {
                                                for(int j4 = i4 + 1;j4 <= n;j4++)
                                                {
                                                    long long mx = max(a[i],max(a[i1],max(a[j],max(a[j1],max(a[i2],max(a[j2],max(a[i3],max(a[j3],max(a[i4],a[j4])))))))));
                                                    if(1LL * a[i] + a[j] + a[i1] + a[j1] + a[i2] + a[j2] + a[i3] + a[j3] + a[i4] + a[j4] > mx * 2)
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
        }
    }
    printf("%d",ret % 998 % 244 % 353);
    return 0;
}
