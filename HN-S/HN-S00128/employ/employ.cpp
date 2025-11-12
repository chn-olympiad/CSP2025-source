#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
string s;
int c[505];
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    cin>>s;
    s=" "+s;
    int flag2=0;
    for(int i=1;i<=n;i++) cin>>c[i],(c[i]==0?(flag2++):0);
    int flag=1;
    for(int i=1;i<=n;i++) if(s[i]!=1){flag=0;break;}
    if(m==n){
        if(flag2!=0||flag!=1) cout<<0,exit(0);
        else cout<<1,exit(0);
    }
    if(flag){
        if(m+flag>n) cout<<0,exit(0);
        int ans=1;
        for(int i=1;i<=m;i++)
            ans*=(n-flag-i+1)
    }

    return 0;
}
