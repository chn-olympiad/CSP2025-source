#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m,maxx;
int a[N];
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        maxx=max(maxx,a[i]);
    }
    cout<<maxx;
    return 0;
}
