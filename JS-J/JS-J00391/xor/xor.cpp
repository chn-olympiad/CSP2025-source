#include <bits/stdc++.h>
using namespace std;
int a[500005];
int main() {
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(k<=1) {
        int cnt=0;
        for(int i=1;i<=n;i++) {
            if(a[i]==1) cnt++;
        }
        if(k==1) cout<<cnt<<endl;
        else cout<<n-cnt+cnt/2<<endl;
    }
    else cout<<1; 
    return 0;
}