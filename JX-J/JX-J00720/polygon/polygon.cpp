#include<bits/stdc++.h>
using namespace std;
long long m,n,k,l,a[1000001];
bool b=1;
int main(){
    freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){cin>>a[i]; if(a[i]!=1) b=0;}
    if(b){k=pow(2,n); m=n*(n+1)/2; l=(k-m)%998244353;
    cout<<l;
}
}
