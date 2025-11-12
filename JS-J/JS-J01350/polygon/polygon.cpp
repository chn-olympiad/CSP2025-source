#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
void f(int k){
    if(k>n){
        return;
    }

}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==3){
        int maxx=0;
        maxx=max(a[1],a[2]);
        maxx=max(maxx,a[3]);
        if(a[1]+a[2]+a[3]>(2*a[maxx])){
            cout<<1;
        }
        else{
            cout<<0;
        }
    }
    return 0;
}
