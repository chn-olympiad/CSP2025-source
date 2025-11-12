#include <bits/stdc++.h>
using namespace std;

int t,n;

struct awa
{
    int a,b,c;
};

bool b[100005];
awa a[100005];
long long maxn = -2147483647;
long long ans = 0;

bool cmp(awa x,awa y)
{
    if(x.a != y.a)
    {
        return x.a > y.a;
    }
    else
    {
        if(x.b != y.b)
        {
            return x.b > y.b;
        }
        else
        {
            return x.c > y.c;
        }
    }
}

void dfs(long long sum,int cnta,int cntb,int cntc,int cnt)
{
    if(cnta > n / 2 || cntb > n / 2 || cntc > n / 2)
    {
        return;
    }
    if(cnt == n)
    {
        ans = max(sum,ans);
        return;
    }
            dfs(sum + a[cnt + 1].a,cnta + 1,cntb,cntc,cnt + 1);
            dfs(sum + a[cnt + 1].b,cnta,cntb + 1,cntc,cnt + 1);
            dfs(sum + a[cnt + 1].c,cnta,cntb,cntc + 1,cnt + 1);
    return;
}

//queue<long long>que;

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    while(t--)
    {
        //memset(b,0,sizeof(b));
        cin >> n;
        ans = 0;
        for(int i = 1;i <= n;i++)
        {
            cin >> a[i].a >> a[i].b >> a[i].c;
        }
        sort(a + 1,a + n + 1,cmp);
        /*for(int i = 1;i <= n;i++)
        {
            que.push(1,1,1,));
        }
        while(que.size() > 1)
        {
            awa x = que.front();
            que.pop();
            awa y = que.front();
            que.pop();
            int maxa = max()
            que.push()
        }
        awa z = que.front();
        cout << z.a << " " << z.b << "" << z.c << endl;*/
        /*for(int i = 1;i <= n;i++)
        {
            cout << a[i].a << " " << a[i].b << " " << a[i].c << endl;
        }*/
        dfs(0,0,0,0,0);
        cout << ans << endl;
    }
    return 0;
}
