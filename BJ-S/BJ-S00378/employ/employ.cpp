#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m;
char c;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++) cin>>c;
    for(int i = 1;i <= n;i++) scanf("%d",&m);
    long long t=1;
    for(int i = 1;i <= n;i++){
        t=(long long)t*i%mod;
    }
    cout<<t;
    return 0;
}
