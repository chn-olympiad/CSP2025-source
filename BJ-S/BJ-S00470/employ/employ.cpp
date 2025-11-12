#include <bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,m,c[510],vis[510],ans;
vector <int> ve;
string s;
void dfs(int dep){
    if(dep>n){
        int cnt=0;
        for(int i=0;i<ve.size();i++){
            if(cnt>=c[ve[i]]){
                cnt++;
                continue;
            }
            else if(s[i]=='0'){
                cnt++;
                continue;
            }
        }
        if(n-cnt>=m){
            ans++;
            ans%=MOD;
        }
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            ve.push_back(i);
            dfs(dep+1);
            vis[i]=0;
            ve.pop_back();
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    int cnt=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='1')  cnt++;
    }
    if(cnt==n){
        int ji=1,d=n;
        for(int i=1;i<=n;i++){
            if(c[i]==0) d--;
        }
        for(int i=1;i<=d;i++){
            ji*=i;
            ji%=MOD;
        }
        if(d<m)cout<<0;
        else cout<<ji;
    }
    else{
        dfs(1);
        cout<<ans;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
