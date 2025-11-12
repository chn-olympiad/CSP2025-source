#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    string s;
    long long n,m,cnt=0;
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=s.size();i++){
        if(s[i]=='1'){
            cnt++;
        }
    }
    cout<<cnt%998244353;
    return 0;
}
