#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans;
vector<int>c(505);
bitset<505>vis;
string s;
bool check(vector<int>v){
    vector<int>t=c;
    bitset<505>dead;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(dead[v[i]]) continue;
        if(s[i]!='0') cnt++;
        else{
            for(int j=i+1;j<n;j++){
                t[v[j]]--;
                if(t[v[j]]==0){
                    dead[v[j]]=1;
                }
            }
        }
    }
    if(cnt>=m){
        return 1;
    }
    else return 0;
}
void dfs(vector<int>v){
    if(v.size()==n){
        if(check(v)){
            //cout<<"here\n";
            //st.insert(v);
            ans++;
            ans%=998244353;
        }
        return ;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            v.push_back(i);
            vis[i]=1;
            dfs(v);
            vis[i]=0;
            v.pop_back();
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    dfs(vector<int>());
    cout<<ans;
    return 0;
}