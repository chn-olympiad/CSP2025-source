#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
Ren5Jie4Di4Ling5%
*/
const int N=550;
const int mod=998244353;
string s;
int c[N];
int n,m;
vector<int>v;
bool vis[N];
int ans;
void dfs(int x){
    if(x==n+1){
        int tmp=0;
        int day=0;
        for(auto i:v){
            ++day;
            if(day-tmp-1<c[i] && s[day-1]=='1')tmp++;
        }
        //cout<<tmp<<"\n";
        if(tmp>=m)ans++;
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            v.push_back(i);
            dfs(x+1);
            v.pop_back();
            vis[i]=0;
        }
    }
    dfs(x+1);
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    bool flag1=1;
    cin>>s;
    for(int i=1;i<=n;i++)cin>>c[i];
    dfs(1);
    cout<<ans;
}
