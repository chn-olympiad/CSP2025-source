#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
const int run_max = 1e7;
struct node
{
    int x,y,z,maxx,maxxx,cmax,cmaxx,tmax,tmaxx;
}a[N];
bool cmp(node x,node y)
{
    return x.maxx>y.maxx;
}
int num[3];
/*int f[35][20][20][20][3];
int maxx[20][20][20];*/
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    mt19937 r(time(0));
    int _;
    cin >> _;
    while(_--)
    {
        num[0] = num[1] = num[2] = 0;
        int n;
        cin >> n;
        for(int i = 1;i<=n;++i)
        {
            cin >> a[i].x >> a[i].y >> a[i].z;
            int maxx = a[i].x,maxxx = 0,cmax = 0,cmaxx = 0,tmax = 0,tmaxx = 0;
            if(maxx<a[i].y)
            {
                maxx = a[i].y;
                maxxx = 1;
            }
            if(maxx<a[i].z)
            {
                maxx = a[i].z;
                maxxx = 2;
            }
            if(maxxx == 0) 
            {
                if(a[i].y>a[i].z)
                {
                    cmax = a[i].y;
                    cmaxx = 1;
                    tmax = a[i].z;
                    tmaxx = 2;
                }
                else
                {
                    cmax = a[i].z;
                    cmaxx = 2;
                    tmax = a[i].y;
                    tmaxx = 1;
                }
            }
            else if(maxxx == 1)
            {
                if(a[i].x>a[i].z)
                {
                    cmax = a[i].x;
                    cmaxx = 0;
                    tmax = a[i].z;
                    tmaxx = 2;
                }
                else
                {
                    cmax = a[i].z;
                    cmaxx = 2;
                    tmax = a[i].x;
                    tmaxx = 0;
                }
            }
            else
            {
                if(a[i].x>a[i].y)
                {
                    cmax = a[i].x;
                    cmaxx = 0;
                    tmax = a[i].y;
                    tmaxx = 1;
                }
                else
                {
                    cmax = a[i].y;
                    cmaxx = 1;
                    tmax = a[i].x;
                    tmaxx = 0;
                }
            }
            a[i].maxx = maxx;
            a[i].maxxx = maxxx;
            a[i].cmax = cmax;
            a[i].cmaxx = cmaxx;
            a[i].tmax = tmax;
            a[i].tmaxx = tmaxx;
        }
        /*if(n<=200)
        {
            int ans = 0;
            for(int i = 1;i<=n;++i)
            {
                for(int d = 1;d*2<=n;++d)
                {
                    for(int dd = 1;dd*2<=n;++dd)
                    {
                        int ddd = n-d-dd;
                        for(int k = 0;k<3;++k)
                        {
                            if(k == 0&&d*2<n)
                             {
                                f[i][d+1][dd][ddd][k] = maxx[d][dd][ddd]+a[i].x;
                                maxx[d+1][dd][ddd] = max(maxx[d+1][dd][ddd],f[i][d+1][dd][ddd][k]);
                                ans = max(ans,f[i][d+1][dd][ddd][k]);
                            }
                            else if(k == 1&&dd*2<n)
                            {
                                f[i][d][dd+1][ddd][k] = maxx[d][dd][ddd]+a[i].y;
                                maxx[d][dd+1][ddd] = max(maxx[d][dd+1][ddd],f[i][d][dd+1][ddd][k]);
                                ans = max(ans,f[i][d][dd+1][ddd][k]);
                            }
                            else
                            {
                                f[i][d][dd][ddd+1][k] = maxx[d][dd][ddd]+a[i].z;
                                maxx[d][dd][ddd+1] = max(maxx[d][dd][ddd+1],f[i][d][dd][ddd+1][k]);
                                ans = max(ans,f[i][d][dd][ddd+1][k]);
                            }
                        }
                    }
                }
            }
            cout << ans << '\n';
            continue;
        }*/
        sort(a+1,a+n+1,cmp);
        int sum = 0;
        for(int i = 1;i<=n;i++)
        {
            if((num[a[i].maxxx]<<1)<n)
            {
                sum+=a[i].maxx;
                ++num[a[i].maxxx];
            }
            else if((num[a[i].cmaxx]<<1)<n)
            {
                sum+=a[i].cmax;
                ++num[a[i].cmaxx];
            }
            else
            {
                sum+=a[i].tmax;
                ++num[a[i].tmaxx];
            }
        }
        int max_sui = run_max/n;
        for(int i = 1;i<=max_sui;++i)
        {
            int cnt = 0;
            num[0] = num[1] = num[2] = 0;
            for(int j = 1;j<=n;++j)
            {
                int s;
                if(a[j].tmax == 0)
                {
                    s = r()%2;
                }
                else
                {
                    s = r()%3;
                }
                if(s == 0)
                {
                    if((num[a[j].maxxx]<<1)<n)
                    {
                        cnt+=a[j].maxx;
                        ++num[a[j].maxxx];
                    }
                    else if((num[a[j].cmaxx]<<1)<n)
                    {
                        cnt+=a[j].cmax;
                        ++num[a[j].cmaxx];
                    }
                    else
                    {
                        cnt+=a[j].tmax;
                        ++num[a[j].tmaxx];
                    }
                }
                else if(s == 1)
                {
                    if((num[a[j].cmaxx]<<1)<n)
                    {
                        cnt+=a[j].cmax;
                        ++num[a[j].cmaxx];
                    }
                    else if((num[a[j].maxxx]<<1)<n)
                    {
                        cnt+=a[j].maxx;
                        ++num[a[j].maxxx];
                    }
                    else
                    {
                        cnt+=a[j].tmax;
                        ++num[a[j].tmaxx];
                    }
                }
                else if(s == 2)
                {
                    if((num[a[j].tmaxx]<<1)<n)
                    {
                        cnt+=a[j].tmax;
                        ++num[a[j].tmaxx];
                    }
                    else if((num[a[j].cmaxx]<<1)<n)
                    {
                        cnt+=a[j].cmax;
                        ++num[a[j].cmaxx];
                    }
                    else if((num[a[j].maxxx]<<1)<n)
                    {
                        cnt+=a[j].maxx;
                        ++num[a[j].maxxx];
                    }
                }
            }
            sum = max(sum,cnt);
        }
        cout << sum << '\n';
    }
    return 0;
}