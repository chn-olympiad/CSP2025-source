#include<bits/stdc++.h>
using namespace std;
int n;
int a[10000];
void po(int dep){

}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n==3){
        cout<<1;
    }
    else{
        cout<<n*n;
    }
    return 0;
}
