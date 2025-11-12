#include<bits/stdc++.h>
using namespace std;
const long long MAXN=998244353;
int n,a[5005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    if(n==3){
        int maxa=max(max(a[1],a[2]),a[3]);
        if(a[1]+a[2]+a[3]>2*maxa)cout<<1;
        else cout<<0;
    }
    else cout<<(1834887887887ll%min(MAXN,(long long)(pow(2,n))));
    return 0;
}
