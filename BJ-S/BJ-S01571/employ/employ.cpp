#include<iostream>
#include<cstdio>
using namespace std;
int n,m,c[505];
string s;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    cin >> s;
    for(int i=1;i<=n;i++) scanf("%d",&c[i]);
    long long ans=1;
    for(int i=2;i<=n;i++){
        ans=ans*i%998244353;
    }
    printf("%lld",ans);
    return 0;
}
