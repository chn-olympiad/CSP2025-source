#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr int N=1e5+99;
#define FOR(i,l,r) for(int i=(int)(l);i<=(int)(r);++i)
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        priority_queue<int>q[3];
        ll ans(0);
        FOR(i,1,n){
            int a[3];
            cin>>a[0]>>a[1]>>a[2];
            FOR(j,0,2)if(a[j]==max({a[0],a[1],a[2]})){
                ans+=a[j];
                q[j].push(max({(0!=j)*a[0],(1!=j)*a[1],(2!=j)*a[2]})-a[j]);
                break;
            }
        }
        FOR(j,0,2)while(q[j].size()*2>n){
            ans+=q[j].top();
            q[j].pop();
        }
        cout<<ans<<'\n';
    }
    return 0;
}
