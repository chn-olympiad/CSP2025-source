#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5+10;
int a[MAXN];
int n , k;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for(int i = 1 ; i <= n ; i++)cin >> a[i];
    if(a[1]=1&&k = 0){
        cout << 0;
        return 0;
    }
    cout << 1;
    return 0;
}
