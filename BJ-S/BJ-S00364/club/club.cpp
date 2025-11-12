#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5+5;
int a[N],b[N],c[N];
int cost[N],to[N];
bool mys(int a,int b){
    return a > b;
}
void solve(){
    int n,ans = 0,cnta=0,cntb=0,cntc = 0;
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
        int mx = max(a[i],b[i]);
        mx = max(c[i],mx);
        if(mx == a[i]){
            cnta++;
            to[i] = 1;
        }
        if(mx == b[i]){
            cntb++;
            to[i] = 2;
        }
        if(mx == c[i]){
            cntc++;
            to[i] = 3;
        }
        ans += mx;
    }
    if(cnta>=n/2){
        int tmp = 0;
        for(int i = 1;i<=n;i++){
            if(to[i]==1)cost[++tmp] = min(a[i]-b[i],a[i]-c[i]);
        }
        sort(cost+1,cost+1+tmp,mys);
        //for(int i = 1;i<=n;i++)cout<<cost[i]<<" ";
        for(int i = cnta;i>n/2;i--){
            ans -= cost[i];
        }
    }
    else if(cntb>=n/2){
        int tmp = 0;
        for(int i = 1;i<=n;i++){
            if(to[i]==2)cost[++tmp] = min(b[i]-a[i],b[i]-c[i]);
        }
        sort(cost+1,cost+1+tmp,mys);
        //for(int i = 1;i<=n;i++)cout<<cost[i]<<" ";
        for(int i = cntb;i>n/2;i--){
            ans -= cost[i];
        }
    }
    else if(cntc>=n/2){
        int tmp = 0;
        for(int i = 1;i<=n;i++){
            if(to[i]==3)cost[++tmp] = min(c[i]-a[i],c[i]-b[i]);
        }
        sort(cost+1,cost+1+tmp,mys);
        //for(int i = 1;i<=n;i++)cout<<cost[i]<<" ";
        for(int i = cntc;i>n/2;i--){
            ans -= cost[i];
        }
    }
    cout<<ans<<'\n';
    return;
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--)solve();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
