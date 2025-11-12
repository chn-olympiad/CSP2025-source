#include<bits/stdc++.h>
using namespace std;
const int N=1e5+6;
int bh[N],val[N];
struct node
{
    int x,bh;
}a[N][4];
void solve()
{
    int n;
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i][1].x>>a[i][2].x>>a[i][3].x;
        for(int j=1;j<=3;j++) a[i][j].bh=j;
        sort(a[i]+1,a[i]+4,[&](node x,node y){return x.x>y.x;});
        bh[i]=a[i][1].bh,val[i]=a[i][1].x-a[i][2].x,ans+=a[i][1].x;
    }
    int js[4]={0,0,0,0};
    for(int i=1;i<=n;i++) js[bh[i]]++;
    int zz=0;
    for(int i=1;i<=3;i++) if(js[i]>n/2) zz=i;
    if(!zz)
    {
        cout<<ans<<'\n';
        return;
    }
    vector<int> w;
    for(int i=1;i<=n;i++) if(bh[i]==zz) w.push_back(val[i]);
    sort(w.begin(),w.end());
    int xx=js[zz]-n/2;
    for(int i=0;i<xx;i++) ans-=w[i];
    cout<<ans<<'\n';
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}