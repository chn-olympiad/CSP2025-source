#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0;
int c[505];
int xl[505];
bool s[505],f[505];
char a;
void pd(){
    int sum=0,fail=0;
    for(int i=1;i<=n;i++){
        if(s[i]&&fail<xl[i])   sum++;
        else{
            fail++;
        }
    }
    if(sum>=m)  ans++;
}
void dfs(int step){
    if(step==n+1){
        pd();
        return ;
    }
    for(int i=1;i<=n;i++){
        if(f[i]==0){
            f[i]=1;
            xl[i]=c[i];
            dfs(step+1);
            f[i]=0;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a;
        s[i]=a-'0';
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    dfs(1);
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
}
