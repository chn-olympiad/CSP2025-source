#include<bits/stdc++.h>
using namespace std;
int mod=998244353;
string s;
int n,k;
int cnt=1;
int a[510];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>k>>s;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=2;i<=n;i++){
        cnt*=i;
        cnt%=mod;
    }
    cout<<cnt;
    return 0;
}
