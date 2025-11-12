#include <bits/stdc++.h>
#define int long long
#define loop(a,b) for (int a = 1 ; a <= b ; ++a)
using namespace std;
struct node{int x,y,z;}a[3000005];
int b[105],f[20005];
bool cmp(node x,node y)
{
    return x.z<y.z;
}
int find(int x)
{
    if (f[x]!=x) f[x]=find(f[x]);
    return f[x];
}
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    loop(i,m)
    {
        cin >> a[i].x >> a[i].y >> a[i].z;
    }
    for (int i = 1 ; i <= k ; ++i)
    {
        cin >> b[i];
        register int t=0;
        loop(j,n)
        {
            cin >> t;
            a[++m]={i+n,j,t};
        }
    }
    sort(a+1,a+m+1,cmp);
    int ans=LONG_LONG_MAX;
    for (int st = 0 ; st < (1<<k) ; ++st)
    {
        loop(i,n+k) f[i]=i;
        register int fx,fy,tan=0;
        loop(i,k)
        {
            if ((1<<(i-1))&st) tan+=b[i];
        }
        loop(i,m)
        {
            if (a[i].x>n&&(!((1<<(a[i].x-(n+1)))&st))) continue;
            fx=find(a[i].x);
            fy=find(a[i].y);
            if (fx!=fy)
            {
                f[fx]=fy;
                tan+=a[i].z;
            }
        }
        ans=min(ans,tan);
    }
    cout << ans << endl;
    return 0;
}