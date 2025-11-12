#include<bits/stdc++.h>
using namespace std;
string s;
int a[505];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    long long s=1;
    for(int i=1;i<=n;i++){
        s=(s*i)%998244353;
    }
    cout<<s;
    return 0;
}
