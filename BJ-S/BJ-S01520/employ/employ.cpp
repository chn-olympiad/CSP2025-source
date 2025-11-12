#include <bits/stdc++.h>
using namespace std;
int n,m;
string s;
int a[505],c[505];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int j=1;
    long long ans=1;
    const int mod=998244353;
    for(int i=1;i<=n-j;i++){
        ans*=(a[i]-i+1);
    }
    cout<<ans;

}
