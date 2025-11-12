#include <bits/stdc++.h>
using namespace std;
const int N=5005;
long long n,a[N],nmax,sum;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        nmax=max(nmax,a[i]);
        sum+=a[i];
    }
    if(sum>nmax*2){
        cout<<1;
    }
    else cout<<0;
    return 0;
}
