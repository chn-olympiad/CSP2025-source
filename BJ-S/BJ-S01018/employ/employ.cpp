#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int m,n,x,a[1000001];
    cin >>m >>n>> x;
    for(int i = 1;i <= m;i++){
        cin >>a[i];
    }
    cout << m*n;
    return 0;
}
