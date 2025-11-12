#include<bits/stdc++.h>
using namespace std;
int n,m,a[10010];
char s[10010];
long long ans = 0;
bool flag = true;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>s[i];
        if(s[i]!='1') flag1 = false;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    if(flag){
        long long o = 1;
        for(int i = 1;i<=n;i++){
            ans = ans%998244353;
            ans *=i;
    }
    }
    cout<<ans%998244353;
    return 0;
}
