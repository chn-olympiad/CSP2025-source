// 2:30+4=6:30

#include<bits/stdc++.h>
using  namespace std;
constexpr int N=1e5+7;
struct node
{
    int v,id,sum;
}love1[N],love2[N];
struct forp
{
    int v,id;
}p[N][5];

bool cmp(node na,node nb)
{
    if(na.v<=nb.v)
        return na.sum<nb.sum;
    return na.v>nb.v;
}
bool pcmp(forp na,forp nb)
{
    return na.v>nb.v;
}
void solve()
{
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=3;j++)
        {
            cin >> p[i][j].v;
            p[i][j].id=j;
        }
        sort(p[i]+1,p[i]+1+3,pcmp);
        love1[i].v=p[i][1].v;
        love1[i].id=p[i][1].id;
        love2[i].v=p[i][2].v;
        love2[i].id=p[i][2].id;
        int x=p[i][1].v+p[i][2].v+p[i][3].v;
        love1[i].sum=love2[i].sum=x;
       // cout << love1[i].v<<' '<<love1[i].id << endl;
       // cout << love2[i].v << ' ' << love2[i].id << endl;
    }
    sort(love1+1,love1+1+n,cmp);
    sort(love2+1,love2+1+n,cmp);
    int sum[5], ans=0;
    sum[1]=sum[2]=sum[3]=n/2;
    for(int i=1;i<=n;i++)
    {

        if(sum[love1[i].id]>0)
        {

            sum[love1[i].id]--;
            ans+=love1[i].v;
        }else
        {
            sum[love2[i].id]--;
            ans+=love2[i].v;
        }
    }
    cout << ans << '\n';
}
int main()
{
    freopen("club.in","r",stdin);
   freopen("club.out","w",stdout);
    int t;
    cin >>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
