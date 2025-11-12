#include<bits/stdc++.h>
using namespace std;
int jiecheng(int a,int b){
    if(a<=b){
        return 1;
    }
    else{
        return a*jiecheng(a-1,b);
    }
}
int n,m;
long long c;
int main(){
    freopen("empoly.in","r",stdin);
    freopen("empoly.out","w",stdout);
    cin>>n>>m;
    c=(jiecheng(n,m)/jiecheng(n-m,1))%998244353;
    if(c>0){
        cout<<c;
    }
    else{
        cout<<'0';
    }
    return 0;
}
