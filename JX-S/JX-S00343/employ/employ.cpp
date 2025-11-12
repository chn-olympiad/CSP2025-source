#include<bits/stdc++.h>
using namespace std;
const int N=5e2+5,M=998244353;
long long n,m,a[N];
char nd[N],zt='A';
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>nd[i];
        if(nd[i]=='0') zt='B';
    }
    for(long long i=1;i<=n;i++) cin>>a[i];
    if(zt=='A'){
        long long s=1;
        for(long long i=2;i<=n;i++) s*=i;
        cout<<s%M;
    }
    return 0;
}
