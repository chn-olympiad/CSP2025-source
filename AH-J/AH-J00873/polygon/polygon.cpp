#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
int n,a[N];
long long dfs(int n){
    if(n==0) return 1;
    else return n*dfs(n-1)%998244353;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    cout<<dfs(n);
    return 0;
}
