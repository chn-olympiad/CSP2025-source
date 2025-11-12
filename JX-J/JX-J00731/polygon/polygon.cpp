#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL n;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    if(n<3){
        cout<<0;
    }else{
        LL a,b,c;
        cin>>a>>b>>c;
        LL num=a+b+c;
        if(num>a*2 && num>b*2 && num>c*2) cout<<1;
        else cout<<0;
    }
    return 0;
}


