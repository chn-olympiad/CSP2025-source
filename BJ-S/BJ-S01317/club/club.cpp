#include<bits/stdc++.h>
//#define int long long
//#define endl '\n'
using namespace std;

int n;

struct Node
{
    int u,v,w;
};

Node a[1000010];
Node b[1000010];
int cnt;

bool cmp1(Node a,Node b)
{
    return (a.u - max(a.v,a.w)) > (b.u - max(b.v,b.w));
}

bool cmp2(Node a,Node b)
{
    return (a.v - a.w) > (b.v - b.w);
}

bool cmp3(Node a,Node b)
{
    return (a.v - max(a.u,a.w)) > (b.v - max(b.u,b.w));
}

bool cmp4(Node a,Node b)
{
    return (a.u - a.w) > (b.u - b.w);
}

bool cmp5(Node a,Node b)
{
    return (a.w - max(a.v,a.u)) > (b.w - max(b.v,b.u));
}

bool cmp6(Node a,Node b)
{
    return (a.u - a.v) > (b.u - b.v);
}

signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    for(int times = 1;times <= t;times++)
    {
        cnt = 0;
        cin >> n;
        for(int i = 1;i <= n;i++)
        {
            cin >> a[i].u >> a[i].v >> a[i].w;
        }

        sort(a + 1,a + 1 + n,cmp1);
        int ans1 = 0;
        int sum1 = 0;
        for(int i = 1;i <= n;i++)
        {
            if(sum1 >= n / 2 || a[i].u - max(a[i].v,a[i].w) < 0)
            {
                b[++cnt] = a[i];
            }
            else
            {
                ans1 += a[i].u;
                sum1++;
            }
        }
        sort(b + 1,b + 1 + cnt,cmp2);
        int sum2 = 0;
        int sum3 = 0;
        for(int i = 1;i <= cnt;i++)
        {
            if(sum3 >= n / 2)
            {
                ans1 += b[i].v;
            }
            else if(sum2 >= n / 2 || b[i].v - b[i].w < 0)
            {
                ans1 += b[i].w;
                sum3++;
            }
            else
            {
                ans1 += b[i].v;
                sum2++;
            }
        }

        sort(a + 1,a + 1 + n,cmp3);
        int ans2 = 0;
        sum1 = 0;
        cnt = 0;
        for(int i = 1;i <= n;i++)
        {
            if(sum1 >= n / 2 || a[i].v - max(a[i].u,a[i].w) < 0)
            {
                b[++cnt] = a[i];
            }
            else
            {
                ans2 += a[i].v;
                sum1++;
            }
        }
        sort(b + 1,b + 1 + cnt,cmp4);
        sum2 = 0;
        sum3 = 0;
        for(int i = 1;i <= cnt;i++)
        {
            if(sum3 >= n / 2)
            {
                ans2 += b[i].u;
            }
            else if(sum2 >= n / 2 || b[i].u - b[i].w < 0)
            {
                ans2 += b[i].w;
                sum3++;
            }
            else
            {
                ans2 += b[i].u;
                sum2++;
            }
        }

        sort(a + 1,a + 1 + n,cmp5);
        int ans3 = 0;
        sum1 = 0;
        cnt = 0;
        for(int i = 1;i <= n;i++)
        {
            if(sum1 >= n / 2 || a[i].w - max(a[i].u,a[i].v) < 0)
            {
                b[++cnt] = a[i];
            }
            else
            {
                ans3 += a[i].w;
                sum1++;
            }
        }
        sort(b + 1,b + 1 + cnt,cmp6);
        sum2 = 0;
        sum3 = 0;
        for(int i = 1;i <= cnt;i++)
        {
            if(sum3 >= n / 2)
            {
                ans3 += b[i].u;
            }
            else if(sum2 >= n / 2 || b[i].u - b[i].v < 0)
            {
                ans3 += b[i].v;
                sum3++;
            }
            else
            {
                ans3 += b[i].u;
                sum2++;
            }
        }

        cout << max(ans1,max(ans2,ans3)) << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
