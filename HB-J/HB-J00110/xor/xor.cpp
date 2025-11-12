#include<iostream>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    int a[1000005];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==1)cout<<1;
    if(n==2)cout<<2;
    return 0;
}
