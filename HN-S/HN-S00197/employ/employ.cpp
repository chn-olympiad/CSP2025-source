#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=510,mod=998244353;
int n,m,c[N],ans;
bitset<N>s,dis;
vector<int>id;
bool check(){
    int cnt=0,res=0;
    for(int i=1;i<=n;i++){
        if(!s[i]||cnt>=c[id[i]])cnt++;
        else res++;
    }
    if(res>=m)return 1;
    else return 0;
}
void dfs(int nw){
    if(nw==n+1){
        if(check())ans++;
        return;
    }
    for(int i=1;i<=n;i++){
        if(dis[i])continue;
        dis[i]=1;
        id.push_back(i);
        dfs(nw+1);
        dis[i]=0;
        id.pop_back();
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        char ch;
        cin>>ch;
       s[i]=ch-'0';
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
        if(!c[i]&&m==n){
            cout<<0;
            return 0;
        }
    }
    id.resize(1);
    dfs(1);
    cout<<ans;
    return 0;
}