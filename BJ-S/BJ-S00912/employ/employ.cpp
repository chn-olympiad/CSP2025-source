#include<bits/stdc++.h>
using namespace std;
int c[510];
const long long MOD=998244353;
int n,m;
string s;
int cnt[510];
bool check(){
    int k=0,num=0;
    for(int i=1;i<=n;i++)
        if(s[i-1]=='0'||c[cnt[i]]<=num)num++;
    k=n-num;
    if(k<m)return 0;
    // for(int i=1;i<=n;i++)
    //     cout<<cnt[i]<<" ";
    // cout<<"\n";
    return 1;
}
long long dfs(int now){
    if(now==0){
        if(check())return 1;
        else return 0;
    }
    long long ans=0;
    for(int i=1;i<=n;i++){
        if(cnt[i]>0)continue;
        cnt[i]=now;
        ans+=dfs(now-1);
        cnt[i]=0;
    }
    return ans;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++)
        cin>>c[i];
    cout<<dfs(n);
    return 0;
}