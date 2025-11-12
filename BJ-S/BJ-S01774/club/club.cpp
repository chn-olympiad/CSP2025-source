#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct p
{
    int value,id;
}a[100005],b[100005],c[100005];

bool cmp(p x,p y)
{
    return x.value>y.value;
}

int ans = -1;
int n;

void dfs(int i,int cnta,int cntb,int cntc,int sum)
{
    ans = max(ans,sum);
    if (cnta<n/2 && i <= n) dfs(i+1,cnta+1,cntb,cntc,sum+a[i].value);
    if (cntb<n/2 && i <= n) dfs(i+1,cnta,cntb+1,cntc,sum+b[i].value);
    if (cntc<n/2 && i <= n) dfs(i+1,cnta,cntb,cntc+1,sum+c[i].value);
}

int main()
{

    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin >> t;
    for (int op = 1;op <= t;op++)
    {
        cin >> n;
        bool r=1;
        for (int i = 1;i <= n;i++)
        {
            cin >> a[i].value >> b[i].value >> c[i].value;
            a[i].id=i;
            b[i].id=i;
            c[i].id=i;
            if (b[i].value!=0&&c[i].value!=0)
            {
                r=0;
            }
        }
        if (r)
        {
            sort(a+1,a+n+1,cmp);
            for (int i = 1;i <= n/2;i++)
            {
                ans+=a[i].value;
            }
        }
        else dfs(1,0,0,0,0);
        cout << ans << endl;
        ans=-1;
    }
    return 0;
}