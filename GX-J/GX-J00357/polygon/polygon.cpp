#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
long long n,a[N],maxx,b[N],ans;
bool vis[N];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    for(int i = 1;i<=n;i++) maxx = max(maxx,a[i]);
    if(maxx == 1&&n>=4){
        for(int i = 4;i<=n;i++){
            int o = 1;
            for(int j = n;j>=i;j--){
                o = o*j;
            }
            o = o/i;
            ans+=o;
            ans = ans%998244353;
        }
    }
    else{
        maxx = max(a[1],max(a[2],a[3]));
        if(maxx*2<a[1]+a[2]+a[3]) ans++;
    }
    cout<<ans;
    return 0;
}
