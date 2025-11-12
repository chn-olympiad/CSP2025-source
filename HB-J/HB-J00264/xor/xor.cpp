#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n, k;
int a[N];
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin>>n>>k;
    if(k==0) {
        bool f=true;
        for(int i=1; i<=n; ++i) {
            cin>>a[i];
            if(!a[i]) f=false;
        }
        if(f) cout<<n/2;
        else {
            int ans=0;
            f=true;
            for(int i=2; i<=n; ++i) {
                if(a[i]==a[i-1] && f) ++ans, f=false;
                else f=true;
            }
            cout<<ans;
        }
        return 0;
    }
    else {
        for(int i=1; i<=n; ++i) {
            cin>>a[i];
        }
        int ans=0;
        bool f=true;
        for(int i=2; i<=n; ++i) {
            if(a[i]!=a[i-1] && f) ++ans, f=false;
            else f=true;
        }
        cout<<ans;
        return 0;
    }
    return 0;
}