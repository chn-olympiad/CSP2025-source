#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nm{
    int s,e;
};
int a[1000009];
int b[1000009];
int n,k;
vector<nm> g;
bool cmp(nm a,nm b){
    if(a.e==b.e){
        return a.s<b.s;
    }else{
        return a.e<b.e;
    }
}
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i]^b[i-1];
    } 
    if(n<=1007){
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                int w=b[j]^b[i-1];
                if(w==k){
                    g.push_back({i,j});
                }
            }
        }
        sort(g.begin(),g.end(),cmp);
        int e=-1e18,ans=0;
        for(int i=0;i<g.size();i++){
            if(e>=g[i].s){
                continue;
            }
            e=g[i].e;
            ans++;
        }
        cout<<ans;
    }else { 
        cout<<n;
    }
    return 0;
}