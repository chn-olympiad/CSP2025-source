#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[501],flag[501],b[501],ans=0;
string s;
void dfs(int cur){
    for(int i=1;i<=n;i++){
        if(flag[i]==0){
            flag[i]=1;
            if(cur==n){
                ans++;
            }else{
                dfs(cur+1);
            }
            flag[i]=0;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    dfs(1);
    cout<<ans%998244353;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
