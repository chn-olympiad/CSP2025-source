#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[505];
int p[505];
bool v[505];
int b[505];
void dfs(int x){
    if(x>n){
        int cnt=0,num=0;
        for(int i=1;i<=n;i++){
            if(!p[i]||cnt>=b[i]){
                cnt++;
            }else{
                num++;
            }
        }
        if(num>=m){
            ans++;
            ans%=998244353;
        }
        return;
    }
    for(int i=1;i<=n;i++){
        if(!v[i]){
            b[x]=a[i];
            v[i]=1;
            dfs(x+1);
            v[i]=0;
        }
    }
    return;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        char x;
        cin>>x;
        p[i]=x-'0';
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1);
    cout<<ans<<endl;
    return 0;
}
