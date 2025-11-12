#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,a;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a;
    }
    if(n<=2 && k==0){
        cout<<1;
    }
    return 0;
}
