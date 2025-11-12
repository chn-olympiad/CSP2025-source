#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    string s;
    int c[100001];
    cin>>n>>m;
    long long ans = 1;
    cin>>s;
    for(int i = 1;i<=n;i++){
        scanf("%d",&c[i]);
    }
    for(int i = 1;i<=n;i++){
        ans*=i;
    }
    printf("%lld",ans%998244353);
    return 0;
}
