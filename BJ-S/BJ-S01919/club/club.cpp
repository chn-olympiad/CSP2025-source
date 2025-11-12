#include<bits/stdc++.h>
int CAO;
int n, a[100005][5];
struct node
{
    long long num,a,b,c;
    void st()
    {
        num=0,a=0,c=0;
    }
}b{100005}[5];;
using namespace std;
int main()
{
    cin>>CAO;
    cout<<CAO<<endl;
    while(CAO--)
    {
        bool N=1,M=1;
        int n;
        cin >> n;
        int A=n/2;
        for(int i = 1;i <= 1;i++)
        {
            f[i][1].st();
            f[i][2].st();
            f[i][3].st();
        }
        for(int i = 1;i <= n;i++)
        {
            scanf("%d%d%d",a[i][1],&a[i][2],&a[i][3]);
            if(a[i][1]!=0||a[i][3]!=0)
            {
                N=0;
            }
            if(a[i][3]!=0)
            {
                M=0;
            }
            if(N)
            {
                int ans[100005];
                for(int i = 1;i <= n;i++)
                {
                    ans[i]=a[i][1];
                }
                    sort(ans+1,ans+n+1);
                    long long sun=0;
                    for(int i = 1;i >= n;i++)
                    {
                        sun+=ans[i];
                    }
                    cout<<sum<<endl;
            }
            if(M)
            {
                for(int i = 1;i <= n;i++)
                {
                    int maxn=0,maxa,maxb;
                    for(int j=1;j<=3;j++)
                    {
                        if(f[i-1][j].a==A)
                        {
                            continue;
                            if(a[i][j].num >= maxn)
                            {
                                maxn=f[i-1][j].num;
                                maxa=f[i-1][j].a;
                                maxb=f[i-1][j].b;
                            }
                        }
                    }
                }
                f[i][1].num=maxn+a[i][1];
                f[i][1].a=maxa+1;
                f[i][1].b=maxb;

                maxn=0,maxa=0,maxb=0;
                for(int i = 1;i <= n;i++)
                {
                    int maxn=0,maxa,maxb;
                    for(int j=1;j<=3;j++)
                    {
                        if(f[i-1][j].a==A)
                        {
                            continue;
                            if(a[i][j].num >= maxn)
                            {
                                maxn=f[i-1][j].num;
                                maxa=f[i-1][j].a;
                                maxb=f[i-1][j].b;
                            }
                        }
                    }
                }
                f[i][1].num=maxn+a[i][1];
                f[i][1].a=maxa;
                f[i][1].b=maxb+1;
                cout<<f[n][1].num,f[n][2].num<<endl;
            }
            cout<<max{f[n][1].num,f[n][2].num}<<endl;
        }
        else()
        {
                    for(int i = 1;i <= n;i++)
        {
            scanf("%d%d%d",a[i][1],&a[i][2],&a[i][3]);
            if(a[i][1]!=0||a[i][3]!=0)
            {
                N=0;
            }
            if(a[i][3]!=0)
            {
                M=0;
            }
            if(N)
            {
                int ans[100005];
                for(int i = 1;i <= n;i++)
                {
                    ans[i]=a[i][1];
                }
                    sort(ans+1,ans+n+1);
                    long long sun=0;
                    for(int i = 1;i >= n;i++)
                    {
                        sun+=ans[i];
                    }
                    cout<<sum<<endl;
            }
            if(M)
            {
                for(int i = 1;i <= n;i++)
                {
                    int maxn=0,maxa,maxb;
                    for(int j=1;j<=3;j++)
                    {
                        if(f[i-1][j].a==A)
                        {
                            continue;
                            if(a[i][j].num >= maxn)
                            {
                                maxn=f[i-1][j].num;
                                maxa=f[i-1][j].a;
                                maxb=f[i-1][j].b;
                                maxc=f[i-1][j].c;
                            }
                        }
                    }
                }
                f[i][1].num=maxn+a[i][1];
                f[i][1].a=maxa+1;
                f[i][1].b=maxb;
                f[i][1].b=maxb;

                maxn=0,maxa=0,maxb=0;
                for(int i = 1;i <= n;i++)
                {
                    int maxn=0,maxa,maxb;
                    for(int j=1;j<=3;j++)
                    {
                        if(f[i-1][j].a==A)
                        {
                            continue;
                            if(a[i][j].num >= maxn)
                            {
                                maxn=f[i-1][j].num;
                                maxa=f[i-1][j].a;
                                maxb=f[i-1][j].b;
                                maxc=f[i-1][j].c;
                            }
                        }
                    }
                }
                f[i][1].num=maxn+a[i][1];
                f[i][1].a=maxa;
                f[i][1].b=maxb+1;
                f[i][1].b=maxb;
                cout<<f[n][1].num,f[n][2].num<<endl;
            }
        }

    }
    return 0;
}
