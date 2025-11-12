#include<bits/stdc++.h>
using namespace std;
int a[505];
int f[505];
int c[505];
int sc[505],z=0;
int main(){
    freopen("employ1.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    string s;
    cin>>n>>m;
    cin>>s;
    for(int i=0;i<s.size();i++){
        a[i+1]=s[i]-'0';
        if(a[i+1]==1) sc[++z]=i;
        f[i+1]=f[i]+a[i+1];
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    if(m>f[n]){
        cout<<0;
        return 0;
    }
    sort(c+1,c+1+n);
    long long ans=1;
    for(int i=1;i<=n;i++){
        if(c[i]>i) continue;
        else ans*=(c[i]-i+1);
        ans%=998244353;
    }
    cout<<ans;
}
