#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define int long long
using namespace std;
const int N=1e5+5;
struct node
{
    int vl[4],mx,bst,mn;
}a[N];
int T,n,ans;
priority_queue<int> q[4];
void init()
{
    ans=0;
    while(q[1].size())q[1].pop();
    while(q[2].size())q[2].pop();
    while(q[3].size())q[3].pop();
}
bool cmp(node a,node b)
{
    return a.mx>b.mx;
}
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    faster;
    cin >> T;
    while(T--)
    {
        init();
        cin >> n;
        for(int i=1;i<=n;i++)
        {
            cin >> a[i].vl[1] >> a[i].vl[2] >> a[i].vl[3];
            
            a[i].mx=max(max(a[i].vl[1],a[i].vl[2]),a[i].vl[3]);

            if(a[i].vl[1]>=a[i].vl[2]&&a[i].vl[1]>=a[i].vl[3])a[i].bst=1;
            else if(a[i].vl[2]>=a[i].vl[1]&&a[i].vl[2]>=a[i].vl[3])a[i].bst=2;
            else if(a[i].vl[3]>=a[i].vl[1]&&a[i].vl[3]>=a[i].vl[2])a[i].bst=3;

            a[i].mn=0;
            for(int j=1;j<=3;j++)
            {
                if(j!=a[i].bst)a[i].mn=max(a[i].mn,a[i].vl[j]);
            }
        }
        sort(a+1,a+n+1,cmp);
        for(int i=1;i<=n;i++)
        {
            int p=a[i].bst;
            if(q[p].size()==n/2)
            {
                int t=q[p].top();
                if(a[i].mx+t>a[i].mn)
                {
                    q[p].pop();
                    q[p].push(-a[i].mx+a[i].mn);
                    ans+=a[i].mx+t;
                }
                else
                {
                    ans+=a[i].mn;
                }
            }
            else
            {
                q[p].push(-a[i].mx+a[i].mn);
                ans+=a[i].mx;
            }
        }
        cout << ans <<'\n';
    }
    return 0;
}