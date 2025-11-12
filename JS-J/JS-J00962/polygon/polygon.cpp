#include<bits/stdc++.h>
using namespace std;
int n,m[5001],last=0;
void sum(int num,int ans,int maxn,int ci){
    cout<<num<<" "<<ans<<" "<<maxn<<endl;
    if(ci>=3 && ans>(maxn*2)){
        last=(last+1)%998244353;
    }
    if(num==n){
        return;
    }
    for(int i=num+1;i<=n;i++){
        sum(i,ans+=m[i],max(maxn,m[i]),ci+1);
    }
}
int main(){
    freopen("polygon.out","w",stdout);
    freopen("polygon.in","r",stdin);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>m[i];
    }
    if(n==3){
        cout<<1;
        return 0;
    }
    for(int i=1;i<=n;i++){
        sum(i,m[i],m[i],1);
    }
    cout<<last;
    return 0;
}

