#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int a[N],b[N],c[N];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin >> t;
    while(t--){
        memset(a,0,sizeof a);
        memset(b,0,sizeof b);
        memset(c,0,sizeof c);
        long long n,ans=0;
        cin >> n;
        for(int i = 1;i<=n;i++){
            cin >> a[i] >> b[i] >> c[i];
        }
        sort(a+1,a+n+1,greater<int>());
        for(int i = 1;i<=n/2;i++){
            ans+=a[i];
        }cout << ans << endl;
    }
    return 0;
}
