#include<bits/stdc++.h>
using namespace std;
int n,m,yang,x,maxn=0;
int fun(int a){
    if(a%2==0){
        return m-(maxn%m);
    }else return maxn%m+1;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        if(i==0) cin>>yang;
        else{
            cin>>x;
            if(x>yang) maxn++;
        }
    }
    int a=maxn/n+1;
    int b=fun(a);
    cout<<a<<" "<<b;
    return 0;
}
