#include<bits/stdc++.h>
using namespace std;
long long n,m;
string s;
int c[1000];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    cin>>s;
    for(int i=1;i<=n;i++){
    scanf("%d",&c[i]);
    }
    long long ans=1;
    for(int i=1;i<=n;i++){
        ans=(1LL*ans*i)%998244353;
    }
    printf("%lld",ans);
    return 0;
}
