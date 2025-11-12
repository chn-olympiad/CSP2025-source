#include<bits/stdc++.h>
using namespace std;
int stair(int n){
    if(n==1)return 1;
    return (n*(stair(n-1))%998244353)%998244353;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int a,b;
    cin>>a>>b;
    string s;
    cin>>s;
    for(int i=0;i<a;i++)cin>>s;
    cout<<stair(a)/stair(a-b)/stair(b);
    return 0;
}
