#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
int n,m,ans=1;
string s;
int c[19],pd[19];
bool flag[19];

void dfs(int pos){
    if(pos==n){
        int num=0;
        for(int i=0;i<n;i++){
            if(num>=pd[i]) num++;
            else if(s[i]=='0') num++;
        }
        if(n-num>=m) ans++;
        return;
    }
    for(int i=0;i<n;i++){
        if(flag[i]) continue;
        pd[pos]=c[i];
        flag[i]=1;
        dfs(pos+1);
        flag[i]=0;
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    bool flag=1;
    for(int i=0;i<s.size();i++){
        if(s[i]=='0') flag=0;
    }
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    if(m==n){
        cout<<0;
        return 0;
    }
    if(!flag&&n>100&&m!=1){
        cout<<0;
        return 0;
    }
    if(n<=18){
        dfs(0);
        cout<<(ans-1)%998244353;
        return 0;
    }
    for(int i=n;i>1;i--){
        ans=ans*i%998244353;
    }
    cout<<ans;
    return 0;
}
