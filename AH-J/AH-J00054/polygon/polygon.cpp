#include <bits/stdc++.h>
using namespace std;
long long n,cnt;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=3;i<=n;i++){
        int ans=n;
        for(int j=n-1;j>n-i;j--){
            ans*=j;
        }
        int t=1;
        for(int j=2;j<=i;j++){
            t*=j;
        }
        cnt+=ans/t;
        cnt%=998244353;
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
