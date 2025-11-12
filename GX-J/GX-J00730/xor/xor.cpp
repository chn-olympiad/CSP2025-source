#include<iostream>        //1^1=0 1^0=1 0^0=0
using namespace std;
int n,k;
int a[1999]={};
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
//    if(n==2){
 //       cout<<;
 //       return 0;
 //   }
    cin>>a[1];
    for(int i=2;i<=n;i++){
        cin>>a[i];
    }
    int t=n*(n-1)/2;
    int ans=t+n;
    cout<<n;
    return 0;
}
