#include <bits/stdc++.h>
using namespace std;
int n, k, a[500005], tp1, tp2, rp, sum1, sum2;
int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin>>n>>k;
    for (int i=1; i<=n; i++) {
        cin>>a[i];
        if (a[i]==0) tp1=1, sum1++;
        else if (a[i]  && a[i]!=1) tp2=1;
        if (a[i]==k) rp++;
        if (a[i]==1) sum2++;
    }
    if (!tp1) {
        if (k==1) cout<<n;
        else if (k==0) cout<<n/2;
        else cout<<rp;
    }else if (!tp2) {
        if (k==1) cout<<sum2+(sum1/2);
        else if (k==0) cout<<sum1+(sum2/2);
        else cout<<rp;
    }
    return 0;
}
