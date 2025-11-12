#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n;
    cin>>n;
    long long x=1;
    for(int i=1;i<=n;i++)x*=i,x%=998244353;
    cout<<x;
    return 0;
}
