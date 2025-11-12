#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,maxn;
int num[5],ans;
struct node{
    int maxn,maxx;
    int maxn_id,maxx_id;
    bool operator<(const node &b) const{
        return maxn-maxx>b.maxn-b.maxx;
    }
}a[100005];
void work()
{
    cin>>n;
    maxn=n/2;
    ans=0;
    memset(num,0,sizeof(num));
    memset(a,0,sizeof(a));
    for(int u,i=1;i<=n;i++)
    {
        for(int j=1;j<=3;j++)
        {
            cin>>u;
            if(u>=a[i].maxn)
            {
                if(a[i].maxn) a[i].maxx=a[i].maxn,a[i].maxx_id=a[i].maxn_id;
                a[i].maxn=u,a[i].maxn_id=j;
            }
            else if(u>=a[i].maxx)
            {
                a[i].maxx=u,a[i].maxx_id=j;
            }
        }
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
        if(num[a[i].maxn_id]+1<=maxn) ans+=a[i].maxn,num[a[i].maxn_id]++;
        else ans+=a[i].maxx,num[a[i].maxx_id]++;
    }
    cout<<ans<<'\n';
    return ;
}
signed main()
{
    // freopen("1.in","r",stdin);
    // freopen("1.out","w",stdout);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--) work();
    return 0;
}
/*
Ren5Jie4Di4Ling5%
*/