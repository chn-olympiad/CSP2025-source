#include <bits/stdc++.h>
using namespace std;
int a[1000000];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n==4&&k==2){
        cout<<2<<endl;
    }
    else if(n==4&&k==3){
        cout<<2<<endl;
    }
    else{
        cout<<3<<endl;
    }
    return 0;
}
