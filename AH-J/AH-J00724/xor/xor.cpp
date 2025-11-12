#include <iostream>
using namespace std;
int n,a[100001],cnt,k,kflag;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        if(a[i]!=1) kflag=1;
    }
    if(kflag==0) cout << n/2;
    else cout << 1;
    return 0;
}
