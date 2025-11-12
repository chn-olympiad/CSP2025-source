#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
long long M=998244353;
bool a[510];
bool user[510];
int s[510];
void dfs(int now,int winer,int loser){
    if(winer==m){
        int anss=1;
        for(int q=now;q<=n;q++){
            anss*=n-q+1;
            anss%=M;
        }
        ans=(ans+anss)%M;
        return;
    }
    if(now==n){
        for(int q=1;q<=n;q++){
            if(!user[q]){
                if(a[now]&&loser<s[q])winer++;
                break;
            }
        }
        if(winer==m)ans++;
        ans%=M;
    }
    if(now<n){
        for(int q=1;q<=n;q++){
            if(!user[q]){
                user[q]=1;
                if(a[now]&&loser<s[q]){
                    dfs(now+1,winer+1,loser);
                } else dfs(now+1,winer,loser+1);
                user[q]=0;
            }
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    bool ttt=0;
    int tttt=0;
    for(int q=1;q<=n;q++){
        char t;
        cin>>t;
        if(t=='1')a[q]=1,tttt++;
        else ttt=1;
    }
    int tt=0;
    for(int q=1;q<=n;q++){
        cin>>s[q];
        if(!s[q])tt++;
    }
    if(!ttt){
        ans=1;
        for(int q=1;q<=n-tt;q++)ans=(ans*q)%M;
        cout<<ans;
        return 0;
    } else if(tttt<m){
        cout<<0;
        return 0;
    }
    dfs(1,0,0);
    cout<<ans;
    return 0;
}
