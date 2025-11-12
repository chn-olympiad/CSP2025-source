#include<bits/stdc++.h>
using namespace std;
long long n[105],m[105];
int main(){
    int x,y;
    cin>>x>>y;
    n[3]=3;
    m[3]=6;
    for(int i=4;i<=100;i++){
        n[i]=i;
        m[i]=i*m[i-1]%998244353;
    }
    cout<<m[x];
    return 0;
}
