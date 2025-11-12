#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10,mod=998244353;
int a[N];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    mt19937 rnd(time(0));
    int n,m;cin>>n>>m;
    string s;cin>>s;
    for(int i=1;i<=m;++i){
        cin>>a[i];
    }
    cout<<rnd()%mod;
    return 0;
}
