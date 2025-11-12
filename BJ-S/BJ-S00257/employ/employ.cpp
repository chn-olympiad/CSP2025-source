#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
string str;
int t[100005];
int a[100005];
int num=-1;
int ans=0;
void dfs(int id,int cnt,int k){
    if(id>n){
        if(cnt>=m){
            ans++;
            ans%=998244353;
        }
    }
    for(int i=1;i<=n;i++){
        if(t[i]==1){
            t[i]=0;
            num+=1;
            if(k>=a[i]){
                dfs(id+1,cnt,k+1);
            }
            else if(str[num]=='0'){
                dfs(id+1,cnt,k+1);
            }
            else{
                dfs(id+1,cnt+1,k);
            }
            t[i]=1;
            num-=1;
        }
    }
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>str;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        t[i]=1;
    }
    dfs(1,0,0);
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
