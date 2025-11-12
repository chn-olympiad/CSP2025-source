#include<bits/stdc++.h>
using namespace std;
namespace YSJ{
    long long n,m,ans,c[505];
    string s;
    int flag[15];
    void js(){
        int x=0,num=0;
        for(int i=1;i<=n;i++){
            if(x>=c[flag[i]]){
                x++;
                continue;
            }
            if(s[i-1]=='0'){
                x++;
            }
            else num++;
        }
        if(num>=m)ans++;
    }
    void dfs(int idx){
        if(idx>n)js();
        for(int i=1;i<=n;i++){
            if(!flag[i]){
                flag[i]=idx;
                dfs(idx+1);
                flag[i]=0;
            }
        }
    }
    int main(){
        cin>>n>>m;
        cin>>s;
        for(int i=1;i<=n;i++)cin>>c[i];
        if(n<=10){
            dfs(1);
            cout<<ans%998244353;
            return 0;
        }
        cout<<ans;
        return 0;
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    return YSJ::main();
}