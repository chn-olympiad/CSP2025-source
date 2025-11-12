#include<bits/stdc++.h>
using namespace std;
string a;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,k,t,i;
    cin >> n;
    for(i=1;i<=n;i++){
        cin >> t;
    }
    if(n<3){
        cout << 0;
    }else if(n==3){
        cout << 1;
    }
    return 0;
}
