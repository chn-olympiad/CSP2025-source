#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005],sum;
int xo(int l,int r){
    int cnt=0;
    for(int i=l;i<=r;i++) cnt=cnt^a[i];
    return cnt;
}
void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) {
        for(int j=i;j<=n;j++){
            if(xo(i,j)==k){
                sum++;
                i=j;
                break;
            }
        }
    }
    cout<<sum;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    solve();
    return 0;
}

