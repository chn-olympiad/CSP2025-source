#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
vector<int>c;
long long res;
vector<int>pl;
bool vis[114];
void dfs(int dep){
    if(dep==n){
        int cnt=0,num=0;
        for(int i=0;i<n;i++){
            if(pl[i]<=num){
                continue;
            }
            if(s[i]=='1'){
                cnt++;
            }
            else{
                num++;
            }
        }
        if(cnt>=m){
            res++;
            res%=998244353;
        }
        return ;
    }
    for(int i=0;i<n;i++){
        if(vis[i])continue;
        vis[i]=1;
        pl.push_back(c[i]);
        dfs(dep+1);
        pl.pop_back();
        vis[i]=0;
    }
    return ;
}
int main(){
	freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    c.resize(n);
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    if(m==n){
        int cnt=0;
        for(int i=0;i<n;i++){
            cnt+=(c[i]>0);
        }
        int cnt2=0;
        for(int i=0;i<n;i++){
            cnt2+=s[i]=='1'?1:0;
        }
        if(cnt==m&&cnt2==m){
            for(int i=1;i<=cnt;i++){
                ret*=i;
                ret%=998244353;
            }
            cout<<ret;
        }
        else{
            cout<<0;
        }
        return 0;
    }
    if(n>=18){
        int cnt=0;
        for(int i=0;i<n;i++){
            cnt+=c[i];
        }
        long long ret=1;
        for(int i=1;i<=cnt;i++){
            ret*=i;
            ret%=998244353;
        }
        cout<<ret;
    }
    else{
        dfs(0);
        cout<<res;
    }
    return 0;
}
