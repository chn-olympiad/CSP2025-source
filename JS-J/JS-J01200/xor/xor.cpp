#include<bits/stdc++.h>
using namespace std;
int n,m,a[500009],sum=0,h[500009];
int main() {
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    int u=0;
    for(int i=1;i<=n;i++) {
        if(a[i]!=1) u=1;
    }
    if(u==0) {
        if(m==0) cout<<n/2*2;
        else if(m==1) cout<<(n-1)/2*2+1;
        else cout<<0;
        return 0;
    }
    int h=0,o=0,g=0;
    for(int i=1;i<=n;i++) {
        if(a[i]!=1&&a[i]!=0) h=1;
        if(a[i]==1) o++;
        if(a[i]==0) g++;
    }
    if(h==0) {
        if(m==1) {
            if(o%2==g%2) cout<<o+g-1;
            else cout<<o+g;
            return 0;
        }
        else if(m==0) {
            if(o%2==g%2) cout<<o+g;
            else cout<<o+g-1;
            return 0;
        }
        else cout<<0;
    }
    cout<<1;
    return 0;
}
