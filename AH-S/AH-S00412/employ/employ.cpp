#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int c[520];
bool f=1;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]!='1') f=0;
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        cin>>c[i];
        if(c[i]!=0) cnt++;
    }
    long long ans=1;
    if(cnt<m) ans=0;
    for(int i=1;i<=cnt;i++){
        ans=ans*i;
    }
    cout<<ans%998244353;
    return 0;
}
