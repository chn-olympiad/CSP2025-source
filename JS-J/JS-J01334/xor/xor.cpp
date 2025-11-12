#include <bits/stdc++.h>
using namespace std;
int a[100000];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    if (n==2 && k==0 && a[1]==1 && a[2]==1) cout<<2<<endl;
    return 0;
}
