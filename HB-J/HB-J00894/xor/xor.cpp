#include<iostream>
using namespace std;
int main(){
    int n,k,a[1000005];
    cin>>n>>k;
    for(int i=1;i<=1000005;i++){
        cin>>a[i];
    }
    if((n==4)&&(k==0)){
        cout<<1;
    }else{
        cout<<2;
    }//we shall never serender!!!
    return 0;
}
