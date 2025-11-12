#include<bits/stdc++.h>
using namespace std;
int n,m;
string s = "";
int c[510] = {};
int mp[510] = {};
int vis[510] = {};
long long ans = 0;
long long mod = 998244353;
bool checkm(){
    int fq = 0;
    int rq = 0;
    for(int i = 1;i<=n;i++){
        //cout<<mp[i]<<" ";
        if(fq>=c[mp[i]]){
            fq++;
        }else{
            if(s[i-1] == '0'){
                fq++;
            }else{
                rq++;
            }

        }
    }
    //cout<<endl;
    //cout<<rq<<" "<<fq<<" ?"<<m<<"   "<<(rq>=m)<<endl;
    if(rq>=m){
        //cout<<"!!!";
        return 1;
    }
    return 0;
}
void dfs(int x){
    if(x > n){
        //cout<<1;
        ans = ans+int(checkm());
        //cout<<checkm();
        ans = ans%mod;
    }
    else{
        for(int i = 1;i<=n;i++){
            if(vis[i] == 0){
                vis[i] = 1;
                mp[x] = i;
                dfs(x+1);
                vis[i] = 0;
            }
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    //cout<<m<<" ";
    cin>>s;
    int cnt2 = 0;
    for(int i = 1;i<=n;i++){
        cin>>c[i];
        if(c[i] == 0){
            cnt2++;
        }
    }
    if(cnt2>n-m){
        cout<<0;
        return 0;
    }
    int cnt = 0;
    for(int i = 0;i<s.size();i++){
            cnt = cnt+s[i]-'0';
    }
    if(cnt == s.size()){
        for(int i = 1;i<=s.size();i++){
            ans = ans*i;
            ans = ans%mod;
        }
        cout<<ans;
        return 0;
    }
    if(cnt<m){
        cout<<0;
        return 0;
    }
    dfs(1);
    cout<<ans;
}
