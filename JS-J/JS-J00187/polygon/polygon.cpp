#include<bits/stdc++.h>
using namespace std;
int n;
int a[21];
long long f(int i,int m,int maxx){
    if(i<=n){
        return f(i+1,m,maxx)+f(i+1,m+a[i],max(maxx,a[i]));
    }
    else{
        if(m>maxx*2)return 1;
        else return 0;
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cout<<f(1,0,0)%998244353;
    return 0;
}
