#include<bits/stdc++.h>
using namespace std;

#define int long long

struct Node
{
    int u,v,c;
};

int jia[10005];
int f[10005];

Node a[20000005];

bool cmp(Node x,Node y)
{
    return x.c<y.c;
}

int se(int x)
{
    if (f[x]==x) return x;
    f[x]=se(f[x]);
    return f[x];
}

void he(int x,int y)
{
    int fx=se(x);
    int fy=se(y);
    if (fx!=fy) f[fy]=fx;
}

signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    for (int i=1;i<=n;i++)
        f[i]=i;
    for (int i=1;i<=m;i++)
        cin >> a[i].u >> a[i].v >> a[i].c;
    int cnt=m;
    for (int i=1;i<=k;i++)
    {
        int q;
        cin >> q;
        for (int j=1;j<=n;j++)
            cin >> jia[j];
        for (int j=1;j<=n;j++)
            for (int l=j+1;l<=n;l++)
            {
                cnt++;
                a[cnt].u=j;
                a[cnt].v=l;
                a[cnt].c=q+jia[j]+jia[l];
            }
    }
    sort(a+1,a+cnt+1,cmp);
    int cur=0;
    int sum=0;
    for (int i=1;i<=cnt && cur<n-1;i++)
    {
        int fu=se(a[i].u);
        int fv=se(a[i].v);
        if (fu!=fv)
        {
            cur++;
            sum=sum+a[i].c;
            he(fu,fv);
        }
    }
    cout << sum << endl;

    return 0;
}
