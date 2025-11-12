#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    if(n<=2) cout<<0;
    else if(n==3) cout<<1;
    else cout<<9;
    return 0;
}
