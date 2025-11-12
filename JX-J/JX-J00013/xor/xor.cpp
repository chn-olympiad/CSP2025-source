#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int a[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,ans=0;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }

    for(int i=1;i<=n;i++){
        if(a[i]==1){
            ans++;
        }
        
    }
    cout << ans;
    return 0;
}
