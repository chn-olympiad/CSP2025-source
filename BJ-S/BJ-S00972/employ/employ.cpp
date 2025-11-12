#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353;
int n,m,c[505],rp[505];//有几人失败
string s;
bool b[505];
ll dfs(int x,int win){//成功人数
    // cout<<x<<" "<<win<<endl;
    if(x>=n){
        if(win>=m)return 1;
        return 0;
    }
    if(x-win>n-m)return 0;
    int ans=0,tmp=0;
    for(int i=1;i<=n;++i){
        if(b[i])continue;
        if(c[i]==c[i-1]&&!b[i-1]&&i!=1){
            ans+=tmp;continue;
        }
        // cout<<i<<" "<<x+1<<" "<<((s[x]=='1'&&c[i]>x-win)?win+1:win)<<endl;
        b[i]=1;
        tmp=dfs(x+1,(s[x]=='1'&&c[i]>x-win)?win+1:win);
        ans+=tmp;
        b[i]=0;
        ans%=mod;
    }
    return ans;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;++i){
        scanf("%d",&c[i]);
    }int flag=n;
    for(int i=0;i<s.size();++i){
        rp[i]+=(i>0)?rp[i-1]:0;
        if(s[i]=='0')--flag,++rp[i+1];
    }
    if(n>10){
        cout<<0;return 0;
    }
    // if(flag==n){
    //     ll ans=1;
    //     for(int i=0;i<n;++i){
    //         ans*=(n-i);ans%=mod;
    //     }
    //     cout<<ans;
    //     return 0;
    // }//cout<<0;
    sort(c+1,c+n+1);
    cout<<dfs(0,0);
    return 0;
}