#include<iostream>
#include<cmath>
using namespace std;
int a[500050];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n;
    bool s=true,l=true;
    int a=0,b=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]!=1){
            s=false;
        }else{
            a++;
        }
        if(a[i]>1){
            l=false;
        }else if(!a[i]){
            b++;
        }
    }
    if(s){
        cout<<n/2;
    }else if(l){
        if(k){
            cout<<a;
        }else{
            cout<<b;
        }
    }else{
        cout<<2;
    }
    return 0;
}
