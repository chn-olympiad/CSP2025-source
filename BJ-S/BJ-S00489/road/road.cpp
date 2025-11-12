#include <bits/stdc++.h>
using namespace std;

long long n,m,k;
long long cnt = 1;

int c[100005];
int a[5005][5005];
bool use[100005];
long long minn=2147484647;
void dfs(long long x,long long sum,long long cot)
{
    if(sum >= minn)
    {
        return;
    }
    if(cot >= n)
    {
        minn = min(minn,sum);
        return;
    }
    for(int i = 1;i <= n + k;i++)
    {
        if(use[i] || a[x][i] == -1)
        {
            continue;
        }
        if(i > n)
        {
            if(use[i])
            {
                dfs(i,sum + a[x][i],cot + 1);
            }
            else
            {
                use[i] = 1;
                sum += c[i];
                dfs(i,sum + a[x][i],cot + 1);
                use[i] = 0;
            }
        }
        else
        {
                    use[i] = 1;
            dfs(i,sum +a[x][i],cot + 1);
                    use[i] = 0;
        }
    }
    return;
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    memset(use,0,sizeof(use));
    memset(a,-1,sizeof(a));
    for(int i = 1;i <= m;i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        a[u][v] = w;
        a[v][u] = w;
    }
    for(int i = 1;i <= k;i++)
    {
        cin >> c[n + i];
        for(int j = 1;j <= n;j++)
        {
            int xx;
            cin >> xx;
            a[j][n + i] = xx;
            a[n + i][j] = xx;
        }
    }
    dfs(1,0,0);
    cout << minn << endl;
    return 0;
}
/*long long head[1000005];
struct edge
{
    long long st;
    long long ed;
    long long val;
    long long next;
    bool vis;
};
edge ma[6000005];

bool use[600005];

void addb(long long st,long long ed,long long val)
{
    ma[cnt].st = st;
    ma[cnt].ed = ed;
    ma[cnt].val = val;
    ma[cnt].next = head[st];
    ma[cnt].vis = false;
    head[st] = cnt++;
    return;
}
long long minn = 2147483647;

void dfs(long long x,long long sum,long long cot)
{
    if(sum >= minn)
    {
        return;
    }
    if(cot >= n)
    {
        //cout << cot << " " << ma[x].st << " " << ma[x].ed << " " << sum << endl;
        //cout << 1919810 << endl;
        minn = min(minn,sum);
        return;
    }
    //cout << 114514 << endl;
    for(long long i = head[x];head[i] != -1;i = ma[i].next)
    {
        //cout << cot << " " << ma[i].st << " " << ma[i].ed << " " << sum << endl;
        if(ma[i].vis)
        {
            continue;
        }
        ma[i].vis = 1;
        if(ma[i].ed <= n)
        {
            dfs(ma[i].ed,sum + ma[i].val,cot + 1);
        }
        else
        {
            if(use[ma[i].ed] == 0)
            {
                use[ma[i].ed] = 1;
                //cout << ma[i].ed - n << " 114514" << endl;
                sum += c[ma[i].ed];
                dfs(ma[i].ed,sum + ma[i].val,cot);
                use[ma[i].ed] = 0;
                continue;
            }
            dfs(ma[i].ed,sum + ma[i].val,cot);
        }
        ma[i].vis = 0;
    }

}

int main()
{
    freopen("road1.in","r",stdin);
    freopen("road1.out","w",stdout);
    memset(head,-1,sizeof(head));
    cin >> n >> m >> k;
    for(long long i = 1;i <= m;i++)
    {
        long long u,v,w;
        cin >> u >> v >> w;
        addb(u,v,w);
        addb(v,u,w);
    }
    for(long long i = 1;i <= k;i++)
    {
        cin >> c[i + n];
        for(long long j = 1;j <= n;j++)
        {
            long long xx;
            cin >> xx;
            addb(n + i,j,xx);
            addb(j,n + i,xx);
        }
    }
    dfs(1,0,1);
    cout << minn << endl;
    return 0;
}
*/
