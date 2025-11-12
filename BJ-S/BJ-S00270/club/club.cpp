#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,t,f[100001][11],ans;
struct node{ll ke[4],dif,mx,mn,md;}a[100001];
ll mxx(ll y){
    ll x=max(a[y].ke[1],max(a[y].ke[2],a[y].ke[3])),aa=a[y].ke[1],bb=a[y].ke[2],cc=a[y].ke[3];
    if (x==aa) return 1;
    if (x==bb) return 2;
    if (x==cc) return 3;
}
ll mnn(ll y){
    ll x=min(a[y].ke[1],min(a[y].ke[2],a[y].ke[3])),aa=a[y].ke[1],bb=a[y].ke[2],cc=a[y].ke[3];
    if (x==aa) return 1;
    if (x==bb) return 2;
    if (x==cc) return 3;
}
bool cmp(node x,node y){
    if (x.dif!=y.dif) return x.dif>y.dif;
    if (x.ke[1]!=y.ke[1]) return x.ke[1]>y.ke[1];
    if (x.ke[2]!=y.ke[2]) return x.ke[2]>y.ke[2];
    return x.ke[3]>y.ke[3];
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while (t--){
        ll cnt[4]={0,0,0,0};
        ans=0;
        cin>>n;
        for (ll i=1;i<=n;i++){
            cin>>a[i].ke[1]>>a[i].ke[2]>>a[i].ke[3];
            a[i].mx=a[i].ke[mxx(i)];
            a[i].mn=a[i].ke[mnn(i)];
            bool vis[4]={0,0,0,0};
            vis[mxx(i)]=vis[mnn(i)]=1;
            if (vis[1]==0) a[i].md=1;
            if (vis[2]==0) a[i].md=2;
            if (vis[3]==0) a[i].md=3;
            a[i].dif=a[i].mx-a[i].ke[a[i].md];
        }
        sort(a+1,a+n+1,cmp);
        for (ll i=1;i<=n;i++){
            if (cnt[mxx(i)]<n/2){
                cnt[mxx(i)]++;
                ans+=a[i].ke[mxx(i)];
            }
            else{
                cnt[a[i].md]++;
                ans+=a[i].ke[a[i].md];
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
