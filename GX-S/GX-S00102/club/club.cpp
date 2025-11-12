#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+7;
ll T,n,ans;
struct node{
    int a,b,c;
}a[N];
void dfs(ll t,ll sum,ll x,ll y,ll z){
    if(x>n/2||y>n/2||z>n/2)return;
    if(t==n+1){
        if(x<=n/2&&y<=n/2&&z<=n/2){
            ans=max(ans,sum);
        }
        return;
    }
    dfs(t+1,sum+a[t].a,x+1,y,z);
    dfs(t+1,sum+a[t].b,x,y+1,z);
    dfs(t+1,sum+a[t].c,x,y,z+1);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i].a>>a[i].b>>a[i].c;
        ans=0;
        dfs(1,0,0,0,0);
        cout<<ans<<endl;
    }
    return 0;
}
