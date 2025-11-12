#include<bits/stdc++.h>
using namespace std;
int a[5009];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    long long n;
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    cout<<n*n;
    return 0;
}
