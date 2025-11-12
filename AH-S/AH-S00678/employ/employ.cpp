#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,M=998244353;
int n,m,c[N],fg[N],q[N],ans;
string s;
void dfs(int cnt){
    if(cnt==n+1){
        //cout<<endl;
        int jg=0,ok=0;
        int f=0;
        for(int i=0;i<s.size();i++){
            //cout<<i<<" "<<jg<<" "<<c[i+1]<<endl;
            if(jg>=q[i+1]){
                f=1;
                break;
            }
            if(s[i]=='0')jg++;
            if(s[i]=='1')ok++;
            if(ok==m){
                break;
            }
        }
        //cout<<ok<<endl;
        //for(int i=1;i<=n;i++)cout<<q[i]<<" ";
        //cout<<endl;
        if(ok==m){
            ans++;
            ans%=M;
            //cout<<jg<<endl;
            //for(int i=1;i<=n;i++)cout<<q[i]<<" ";
            //cout<<endl;
        }
    }
    for(int i=1;i<=n;i++){
        if(!fg[i]){
            fg[i]=1;
            q[cnt]=c[i];
            dfs(cnt+1);
            fg[i]=0;
        }
    }
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    dfs(1);
    cout<<ans%M<<endl;
    return 0;
}

