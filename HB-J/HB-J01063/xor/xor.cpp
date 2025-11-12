#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[1001];
int main(){
    freopen("polygon.in","w",stdin);
    freopen("polygon.out","r",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cout<<a[1];
    return 0;
}
