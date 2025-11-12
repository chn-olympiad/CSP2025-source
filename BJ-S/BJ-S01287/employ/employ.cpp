#include<bits/stdc++.h>
using namespace std;
int n,m;
char s[510];
int t[510];
int a[510];
bool used[510];
long long ans;
void dfs(int x){
    if(x==n+1){
        long long cnt=0;
        long long sum=0;
        int h=0;
        for(int i=1;i<=n;i++){
            h++;
            if(cnt>=t[a[i]]){
                cnt++;
                continue;
            }
            if(s[h]=='0'){
                cnt++;
            }else{
                sum++;
            }
        }

        if(sum>=m){
            ans++;
            ans%=998244353;
        }
        return ;
    }
    for(int i=1;i<=n;i++){
        //cout<<i<<" "<<used[i]<<endl;
        if(used[i]==1||i==a[x-1]) continue;
        a[x]=i;
        used[i]=1;
        dfs(x+1);
        used[i]=0;
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    for(int i=1;i<=n;i++){
        cin>>t[i];
    }
    dfs(1);
    cout<<ans;
    return 0;
}
