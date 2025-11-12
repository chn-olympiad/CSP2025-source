#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10,M=998244353;
int n,m,c[N],ans,a[N];
string s;
bool vis[N];
void cal(){
    int fail=0,cnt=0;
    for(int i=1;i<=n;i++){
        if(s[i]=='1'&&c[a[i]]>fail){cnt++;}
        else fail++;
    }
    if(cnt>=m)ans=(ans+1)%M;
}
void dfs(int id){
    if(id>n){cal();return;}
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;a[id]=i;
            dfs(id+1);
            vis[i]=0;
        }
    }
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    bool flag=0;
    scanf("%lld%lld",&n,&m);cin>>s;s='0'+s;
    for(int i=1;i<=n;i++)if(s[i]=='0')flag=1;
    for(int i=1;i<=n;i++)scanf("%lld",&c[i]);
    if(n<=10){
        dfs(1);
        printf("%lld\n",ans);
        fclose(stdin);fclose(stdout);
        return 0;
    }
    if(!flag){
        int ans=1;
        for(int i=1;i<=n;i++)ans=ans*i%M;
        printf("%lld\n",ans);
    }
    fclose(stdin);fclose(stdout);
    return 0;
}