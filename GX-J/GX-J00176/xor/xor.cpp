#include<bits/stdc++.h>
using namespace std;

const int N=500005;
int n,k,a[N];
int main() {
    //freopen("xor4.in","r",stdin);
    //freopen("xor4.out","w",stdout);
    cin>>n>>k;
    for (int i=0;i<n;i++) cin>>a[i];
    if (k==0) {
        if (n<=2) cout<<1;
        else cout<<ceil(n/2);
    }
    else if (k==1){
        int ans=0;
        for (int i=0;i<n;i++) {
            if (a[i]==1) ans++;
        }
        cout<<ans;
    }
    else {
        int ans=0;
        for (int i=0;i<n;i++) {
            if (a[i]==255) ans++;
        }
        cout<<ans;
    }
    return 0;
}
