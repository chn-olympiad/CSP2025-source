#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ll np=998244353;
    cin>>n;
    ll m=n;
    for(int i=1;i<m;i++)
        n=(n*i)%p;
    cout<<n;
}
