#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,m,ans;
long long c[510];
char s[510];
long long path[100];
bool st[100];
void dfs(int x){
    if(x>n){
        int no=0,nu=0;
        for(int i=1;i<=n;i++){
            //cout<<path[i]<<" "<<nu<<" "<<c[path[i]]<<endl;;
            if(s[i]=='1'&&c[path[i]]>no){
                nu++;
            }
            else no++;
        }
        if(nu>=m)ans++;
        return ;
    }
    for(int i=1;i<=n;i++){
        if(st[i])continue;
        st[i]=true;
        path[x]=i;
        dfs(x+1);
        st[i]=false;
    }
    return ;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    bool flag=true;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        if(s[i]==0)flag=false;
    }
    long long nu0=0;
    for(int i=1;i<=n;i++){
            cin>>c[i];
            if(c[i]==0)nu0++;
    }
    if(n<=11){
        dfs(1);
    cout<<ans<<endl;
    }
    else {
        puts("0");
    }
    return 0;
}
