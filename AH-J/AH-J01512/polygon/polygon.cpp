#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e3+10;
const int INF = 998244353;
int n,a[N],ans,sum;
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    const char endl = '\n';
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    sum=a[1]+a[2];
    for(int i=3;i<=n;i++){
        if(sum>a[i]){
            ans=(ans+1)%INF;
        }
        sum+=a[i];
    }
    cout<<ans;
    return 0;
}
