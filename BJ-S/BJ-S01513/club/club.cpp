#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
int n;
ll a[N],b[N],c[N],d[N];
vector<ll> cnta,cntb,cntc;
bool cmp(int x,int y){
    return x>y;
}
void solve(){
    cnta.clear();
    cntb.clear();
    cntc.clear();
    cin >>n;
    ll sum=0;
    for(int i=1;i<=n;i++){
        cin >>a[i]>>b[i]>>c[i];
        if(a[i]>=b[i] && a[i]>=c[i]){
            cnta.push_back(i);
        }else if(b[i]>=a[i] && b[i]>=c[i]){
            cntb.push_back(i);
        }else if(c[i]>=a[i] && c[i]>=b[i]){
            cntc.push_back(i);
        }
        sum+=max({a[i],b[i],c[i]});
    }
    if(cnta.size()>n/2){
        int idx=0;
        for(int v:cnta){
            d[++idx]=max(b[v]-a[v],c[v]-a[v]);
        }
        sort(d+1,d+idx+1,cmp);
        for(int i=1;i<=cnta.size()-n/2;i++){
            sum+=d[i];
        }
    }else if(cntb.size()>n/2){
        int idx=0;
        for(int v:cntb){
            d[++idx]=max(a[v]-b[v],c[v]-b[v]);
        }
        sort(d+1,d+idx+1,cmp);
        for(int i=1;i<=cntb.size()-n/2;i++){
            sum+=d[i];
        }
    }else if(cntc.size()>n/2){
        int idx=0;
        for(int v:cntc){
            d[++idx]=max(a[v]-c[v],b[v]-c[v]);
        }
        sort(d+1,d+idx+1,cmp);
        for(int i=1;i<=cntc.size()-n/2;i++){
            sum+=d[i];
        }
    }
    cout <<sum<<"\n";
    return ;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin >>t;
    while(t--){
        solve();
    }
    return 0;
}
