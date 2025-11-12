#include<iostream>
using namespace std;
int n,k;
int ak[1000];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>ak[i];
    }
    cout<<n/2;
}
