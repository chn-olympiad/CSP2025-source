//GZ-S00018 伍珈呈 贵州师范大学云岩实验中学
#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m,zero=0;
    cin>>n>>m;
    string s;
    int c[505];
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>c[i];
        if(c[i]==0){
            zero++;
        }
    }
    long long ans=1;
    for(int i=n-zero;i>=n-m-zero;i--){
        ans=(ans*i)%998244353;
    }
    cout<<ans;
    return 0;
}
