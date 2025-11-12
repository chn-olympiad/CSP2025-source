#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n;
    cin>> n;
    int n1=n;
    long long sum=1;
    for(int i=2;i<=n;i++) sum=(sum*i)%998244353;
    cout<< sum;
    return 0;
}

