#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
ll T,n,ans;
struct node{
    ll x,y,z,tmp;
}a[N];
vector<node> v[4];
bool cmp(node X,node Y){
    return X.tmp-max(X.x,max(X.y,X.z))<Y.tmp-max(Y.x,max(Y.y,Y.z));
}
void solve(){
    ans=0;
    for(int i=0;i<4;i++)v[i].clear();
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y>>a[i].z;
        // a[i].pos=i;
    }
    for(int i=1;i<=n;i++){
        ll maxn=max(a[i].x,max(a[i].y,a[i].z));
        if(a[i].x==maxn){
            v[1].push_back((node){0,a[i].y,a[i].z,a[i].x});
            ans+=a[i].x;
        }else if(a[i].y==maxn){
            v[2].push_back((node){a[i].x,0,a[i].z,a[i].y});
            ans+=a[i].y;
        }else{
            v[3].push_back((node){a[i].x,a[i].y,0,a[i].z});
            ans+=a[i].z;
        }
    }
    // cout<<ans<<"\n";
    for(int i=1;i<=3;i++){
        if(v[i].size()>n/2){
            // cout<<i<<" "<<v[i].size()<<"\n";
            sort(v[i].begin(),v[i].end(),cmp);
            for(int j=0;j<(v[i].size()-n/2);j++){
                // cout<<v[i][j].x<<" "<<v[i][j].y<<" "<<v[i][j].z<<" "<<v[i][j].tmp<<"\n";
                ans+=max(v[i][j].x,max(v[i][j].y,v[i][j].z))-v[i][j].tmp;
            }
        }
    }
    cout<</*"ans: "<<*/ans<<"\n";
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--)solve();
    return 0;
}