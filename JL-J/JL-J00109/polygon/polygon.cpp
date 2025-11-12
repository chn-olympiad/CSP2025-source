#include <bits/stdc++.h>
using namespace std;
int n;
int a[5050];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==1) cout<<0;
    else cout<<n;
    return 0;
}
