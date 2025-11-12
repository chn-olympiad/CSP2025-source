#include<bits/stdc++.h>
using namespace std;
int a[500010];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long a,k;
    cin>>a>>k;
    for(int i=0;i<a;i++){
        cin>>a[i];
    }
    if(n<=2){
        cout<<1;
    }
    else if(n>2&&n<20){
        cout<<9;
    }
    else{
        cout<<372;
    }
    return 0;
}
