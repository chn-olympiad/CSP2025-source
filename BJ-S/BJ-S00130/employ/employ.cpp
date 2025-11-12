#include <iostream>
#include <vector>
using namespace std;
#define int long long
const int N=20,M=270000,Mod=998244353;
int n,m,c[N],p[N],f[N]={1},g[N],ans;
bool vis[N];
string s;
void dfs(int x,int k){
    if(x==n+1){
        if(k<m)return ;
        int res=1,cnt=0;
        vector <int> v[2];
        for(int i=1;i<=n;i++){
            //cout << vis[i];
            if(s[i]=='1')v[vis[i]].push_back(i);
            else cnt++;
        }
        //cout << endl;
        for(int i=0,num;i<v[0].size();i++){
            num=g[p[v[0][i]]];
            res=res*(num-i)%Mod;
        }
        for(int i=v[1].size()-1,num;i>=0;i--){
            num=g[n]-g[p[v[1][i]]];
            //cout << num<<endl;
            res=res*(num+i-v[1].size()+1)%Mod;
        }
        res=res*f[cnt]%Mod;
        ans=(ans+res)%Mod;
        return ;
    }
    dfs(x+1,k);
    if(s[x]=='1'){
        vis[x]=1;
        dfs(x+1,k+1);
        vis[x]=0;
    }
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>s;
    s=' '+s;
    for(int i=1;i<=n;i++){
        cin>>c[i];
        g[c[i]]++;
    }
    for(int i=1;i<=n;i++){
        f[i]=f[i-1]*i%Mod;
        p[i]=p[i-1]+(s[i]=='0');
        g[i]=g[i-1]+g[i];
    }
    //sort(c+1,c+n+1);
    dfs(1,0);
    cout << ans << endl;
    return 0;
}
