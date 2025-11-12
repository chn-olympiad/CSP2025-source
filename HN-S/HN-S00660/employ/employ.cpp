#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    int num = 1;
    for(int i = 1;i <= n;++i)
        num = num * i % 998244353;
    cout<<num;
    return 0;
}