#include<bits/stdc++.h>
using namespace std;
int n,m,ans=1;
string s;
int c[600];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    cin>>s;
    for(int i=1;i<=n;i++){
        scanf("%d",&c[i]);
    }
    for(int i=1;i<=n;i++){
        ans*=i;
        ans%=998244353;
    }
    printf("%d",ans);
    return 0;
}
