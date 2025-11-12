#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n;
    cin>>n;
    if(n==3){
        int a,b,c;
        cin>>a>>b>>c;
        if((a+b)>c or (b+c)>a or (a+c)>b){
            cout<<1;
        }
    }
    return 0;
}
