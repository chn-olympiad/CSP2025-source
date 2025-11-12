#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct node{int v,id;}a[N][5];
int t;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("club.in","r",stdin);freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        int n,ans=0;cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i][1].v>>a[i][2].v>>a[i][3].v;
            a[i][1].id=1,a[i][2].id=2,a[i][3].id=3;
            sort(a[i]+1,a[i]+4,[](node x,node y){return x.v>y.v;});
        }
        priority_queue<int> q[5];
        for(int i=1;i<=n;i++) q[a[i][1].id].push(a[i][2].v-a[i][1].v),ans+=a[i][1].v;
        for(int i=1;i<=3;i++) while(int(q[i].size())>n/2) ans+=q[i].top(),q[i].pop();
        cout<<ans<<"\n";
    }
    return 0;
}