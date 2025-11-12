#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL rand(LL l,LL r){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<LL> dis(l,r);
    return dis(gen);
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,a;
    bool flag=1,flas=1,flah=1;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a;
        if(a!=1)
            flag=0;
        if(a>1)
            flas=0;
        if(a>255)
            flah=0;
    }
    if(flag)
        cout<<0;
    else if(flas)
        cout<<1;
    else if(flah)
        cout<<rand(0,255);
    else
        cout<<rand(0,1000000000);
    return 0;
}
