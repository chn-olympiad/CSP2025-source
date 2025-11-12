#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int a,b;
    cin>>a>>b;
    string s;
    cin>>s;
    for(int i=1;i<=a;i++){
        cin>>b;
    }
    long long ans=1;
    for(int i=3;i<=s.size();i++){
        ans*=i%998244353;
    }
    cout<<ans;
    return 0;
}
