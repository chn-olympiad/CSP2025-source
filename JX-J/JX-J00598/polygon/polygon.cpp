#include<bits/stdc++.h>
#define M 998244353
using namespace std;
int n;
int a[5001];
long long b[5001];
long long sum;
int c[5001];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon,out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        b[i]=b[i-1]+a[i];
        c[i]=(c[i-1]*i)%M;
    }
    if(b[n-1]<a[n]) cout<<0;
    else cout<<c[n]%M;
}