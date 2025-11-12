#include <iostream>
using namespace std;
int n,m,a[505],b[505],ans,f[505];
string s;
void dfs(int sum,int p){
    for(int i=0;i<s.length();i++){
        if(p>=a[i]){
            p++;
            continue;
        }
        if(s[i]=='1'){
            sum++;
        }else{
            p++;
        }
        if(sum>=m){
           ans++;
           return ;
        }
    }
}
void d(int x){
    for(int i=0;i<n;i++){
            if(f[i]==0){
               a[i]=b[x];
               f[i]=1;
            }else{
                continue;
            }
            if(x!=n-1){
                d(x+1);
            }
            if(x==n-1){
            dfs(0,0);
            }
            f[i]=0;
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    d(0);
    cout<<ans;
    return 0;
}
