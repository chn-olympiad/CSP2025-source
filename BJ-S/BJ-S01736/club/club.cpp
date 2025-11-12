#include<iostream>
#include<queue>
using namespace std;
#define int long long
const int N = 1e5 + 5;

int t,n,a[N][4],b[4];

struct node
{
    int num, diff, pos1, pos2;
} x[N];

bool operator > (node a,node b)
{
    return a.diff > b.diff;
}

priority_queue<node,vector<node>,greater<node> > q[4];

signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n; int ans = 0;
        for(int j=1;j<=3;j++)
        {
            while(!q[j].empty()) q[j].pop();
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=3;j++)
                cin >> a[i][j];
            for(int j=1;j<=3;j++) b[j] = a[i][j];
            if(b[1] < b[2]) swap(b[1],b[2]);
            if(b[1] < b[3]) swap(b[1],b[3]);
            if(b[2] < b[3]) swap(b[2],b[3]);
            x[i].num = b[1]; x[i].diff = b[1] - b[2];
            for(int j=1;j<=3;j++) if(b[1] == a[i][j]) x[i].pos1 = j;
            for(int j=1;j<=3;j++) if(b[2] == a[i][j]) x[i].pos2 = j;
        }
        for(int i=1;i<=n;i++)
        {
            q[x[i].pos1].push(x[i]); ans += x[i].num;
            if(q[x[i].pos1].size() > n / 2)
            {
                node p = q[x[i].pos1].top(); q[x[i].pos1].pop();
                ans -= p.diff;
                q[p.pos2].push(p);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
