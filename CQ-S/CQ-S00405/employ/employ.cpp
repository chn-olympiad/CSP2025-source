#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans;
string s;
int c[505];
void dfs(int u,int a[],bool f[]){
    if(u>n){
        int cnt=0,tot=0;
        for(int i=1;i<=n;i++){
            if(s[i]=='0'){
                cnt++;
            }else{
                if(cnt>=c[i]){
                    cnt++;
                }else{
                    tot++;
                }
            }
        }
        if(tot>=m){
            ans++;
            ans%=998244353;
        }
        return ;
    }
    for(int i=1;i<=n;i++){
        if(f[i]==0){
            a[u]=c[i];
            f[i]=1;
            dfs(u+1,a,f);
            f[i]=0;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    s=" "+s;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    if(n<=11){
        int a[15]={0};
        bool f[15]={0};
        dfs(1,a,f);
    }
    return 0;
}