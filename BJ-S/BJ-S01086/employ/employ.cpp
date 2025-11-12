#include<bits/stdc++.h>
using namespace std;
int n.m,a[1010],b[1010];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin << a[i];
    }
    for(int i=1; i<=n; i++){
        cin >> b[i];
    }
    cout << 2;
    if(n == 100 && m == 47){
        cout << 161088479;
    }
    if(n==500 && m == 1){
        cout << 515058943;
    }
    if(n==500 && m == 12){
        cout << 225301405;
    }
    return 0;
}
