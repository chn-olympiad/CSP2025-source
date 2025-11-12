#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5005,mod=998244353;
int n,a[N];
int ans=0;
int tmp[N];
signed main() {
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    do {
        for(int len=3;len<=n;len++) {
            int sum=0;
            int cnt=0;
            for(int i=1;i<=len;i++) sum+=a[i];
            if(*max_element(a+1,a+1+len)*2 < sum) {
                ans++;
            }
        }
    }while(next_permutation(a+1,a+1+n));
    cout<<ans%mod;
    return 0;
}