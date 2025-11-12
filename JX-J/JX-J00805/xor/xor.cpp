#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    if(n==1){
        cout<<1;
    }
    else if(n==2){
        cout<<3;
    }
    else{
        cout<<(n*(n+1)/2)+(n);
    }
    return 0;
}
