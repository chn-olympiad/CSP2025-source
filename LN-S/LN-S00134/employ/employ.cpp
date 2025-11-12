#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,m,a[510],s[510],flag[510];
char str[114514];
int cnt;
void dfs(int k,int c){
    if(k==n+1){
        cnt++;
        return ;
    }
    for(int i=1;i<=n;i++){
        if(!flag[i]){
            if(str[k]=='1'&&c<a[i]) {
                flag[i]=1;
                dfs(k+1,c);
                flag[i]=0;
            }
            else{
                flag[i]=1;
                dfs(k+1,c+1);
                flag[i]=0;
            }
        }
    }
}
bool check(char *str){
    for(int i=0;str[i];i++){
        if(str[i]!='1') return 0;
    }
    return 1;
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>str+1;
    s[1]=1;
    for(int i=2;i<=n;i++){
        s[i]=(i*s[i-1])%mod;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==n){
        for(int i=1;i<=n;i++){
            if(str[i]!='1'||a[i]==0){
                cout<<0<<"\n";
                return 0;
            }
        }
        cout<<1<<"\n";
        return 0;
    }
    else if(m==1){
        for(int i=1;i<=n;i++){
            if(str[i]=='1'){
                int cnt=0;
                for(int j=1;j<=n;j++){
                    if(a[j]>=i){
                        cnt++;
                    }
                }
                cout<<cnt*s[n-1]%mod<<"\n";
                return 0;
            }
        }
        cout<<0<<"\n";
        return 0;
    }
    else {
        dfs(1,0);
        cout<<cnt<<"\n";
        return 0;
    }
}
//tainanlewozuobuchulaiCCFmingnianbatichujiandandian...
