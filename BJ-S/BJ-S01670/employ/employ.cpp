#include<bits/stdc++.h>
using namespace std;
int n,m,c[506],vis[506],box[506],ans,h[506];
string s;
const int mod=998244353;
void dfs(int cur){
    if(cur>n){
        int p=0,cnt=0;
        for(int i=1;i<=n;i++) h[i]=c[i];
        for(int i=1;i<=n;i++){
            if(s[i]=='0'&&c[box[i]]!=-1){
                p++;
                int tmp=p;
                for(int j=i+1;j<=n;j++){
                    if(p>=c[box[j]]&&c[box[j]]!=-1){
                        tmp++;
                        c[box[j]]=-1;
                    }
                }
                p=tmp;
            }
            if(s[i]=='1'&&c[box[i]]!=-1) cnt++;
        }
        for(int i=1;i<=n;i++) c[i]=h[i];
        if(cnt>=m) ans++;
        ans=(ans%mod);
        return ;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            vis[i]=1;
            box[cur]=i;
            dfs(cur+1);
            vis[i]=0;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    s='#'+s;
    for(int i=1;i<=n;i++) cin>>c[i];
    if(n<=18){
        dfs(1);
        cout<<ans;
    }else{
        cout<<0;
    }
    return 0;
}
