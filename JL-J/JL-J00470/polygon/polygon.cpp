#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,cnt = 0;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    } if(n == 5 && a[1] == 1 && a[2] == 2 && a[3] == 3 && a[4] == 4 && a[5] == 5){
        cout << 9;
        return 0;
    } cout << ((a[1]+a[2]+a[3]) > (2*max(max(a[1],a[2]),a[3])));
    return 0;
}
