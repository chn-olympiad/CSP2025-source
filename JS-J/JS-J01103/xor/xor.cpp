#include<bits/stdc++.h>
using namespace std;
int a,b,c[100001],d,e,f;
int main(){
    cin>>a,b;
    for(int i=0;i<a;i++){
        cin>>c[i];
        if(c==0){
            d=d+1;
        }
    }
    cout<<d;
    return 0;
}
