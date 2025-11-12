#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct pair_
{
    int a,b,c,d;
}e[N];
bool cmp(const pair_&x,const pair_&y)
{
    if(x.d==y.d)
    {
        if(x.d>=0)
        {
            return 1;//让x向前靠
        }
        else return 0;
    }
    return x.d>y.d;
}
void solve()
{
    int n;//成员数量
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>e[i].a>>e[i].b>>e[i].c;
        e[i].d=e[i].a-e[i].b;
    }
    sort(e+1,e+n+1,cmp);
    int ans=0;
    for(int i=1;i<=(n>>1);i++)
    {
        ans+=e[i].a;
    }
    for(int i=(n>>1)+1;i<=n;i++)
    {
        ans+=e[i].b;
    }
    cout<<ans<<endl;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}
