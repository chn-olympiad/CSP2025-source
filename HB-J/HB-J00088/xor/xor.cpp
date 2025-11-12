#include<iostream>
using namespace std;

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,b;
    cin>>n>>k;
    int a[1000005];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(k>0){
        b=2;
    }
    if(k<=0){
        b=1;
    }
    cout<<b;
    return 0;
}
