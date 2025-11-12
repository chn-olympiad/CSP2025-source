#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+10;
ll t,n,maxn;
bool flag1,flag2;
struct student{
    ll x,y,z;
}a[N];
bool cmp(const student &x,const student &y){
    return x.x>y.x;
}
void dfs(ll x,ll y,ll z,ll i,ll sum){
    if(i==n+1){
        maxn=max(maxn,sum);
        return;
    }
    if(x<n/2) dfs(x+1,y,z,i+1,sum+a[i].x);
    if(y<n/2) dfs(x,y+1,z,i+1,sum+a[i].y);
    if(z<n/2) dfs(x,y,z+1,i+1,sum+a[i].z);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
        flag1=true;
        flag2=true;
        cin>>n;
        for(ll i=1;i<=n;i++){
            cin>>a[i].x>>a[i].y>>a[i].z;
            if(a[i].y!=0) flag1=false;
            if(a[i].z!=0) flag2=false;
        }
        if(flag1&&flag2){
            ll ans;
            sort(a+1,a+1+n,cmp);
            for(ll i=1;i<=n/2;i++) ans+=a[i].x;
            cout<<ans;
            continue;
        }
        maxn=0;
        dfs(0,0,0,1,0);
        cout<<maxn<<'\n';
    }
    return 0;
}
