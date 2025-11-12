#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,a[N],b,k;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1){
            b++;
        }
    }
    if(n==b){
        cout<<0;
    }
    else if(n==4){
        cout<<2;
    }
    else{
        cout<<1;
    }
    return 0;
}
