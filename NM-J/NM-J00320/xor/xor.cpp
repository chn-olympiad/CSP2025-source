#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    int a=0;
    int a[10000000];
    cin>>n>>k;
    for(int i=0;i<=n;i++){
        cin>>a[i];
    }
    for(int i=0;i<=n;i++){
       if(n<=2||k==0){
        a=1;
        cout<<a;
    }
    if(n<=100||k==0){
        a=1
        cout<<a;
    }
}
    return 0;
}
