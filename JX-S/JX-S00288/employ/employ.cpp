#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","r",stdout);
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    int a[505];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        if(s[i]=='0') cnt++;
    }
    if(cnt==n) cout<<0;
    if(m==1 and cnt!=0) cout<<n%998244353;
}
