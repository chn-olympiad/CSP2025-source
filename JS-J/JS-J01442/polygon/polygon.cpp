#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int s[5005];
int n;
bool vis[5005];
int sum;
vector <int> v;
bool check(){
    if(v.size()<3) return false;
    int mmax=0,msum=0,csum=0;
    for(auto x:v){
        msum+=s[x];
        mmax=max(mmax,s[x]);
        if(vis[x]) csum++;
    }
    if(csum==v.size()) return false;
    if(msum>mmax*2 ){
        return true; 
    } 
    else return false;
}
void dfs(int i){
    if(i>n) return;
    v.push_back(i);
    if(check()){
        sum=(sum+1)%MOD;
    } 
    vis[i]=1;
    dfs(i+1);
    vis[i]=0;
    v.pop_back();
    if(check()){
         sum=(sum+1)%MOD;
    }
    dfs(i+1);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>s[i];
    dfs(1);
    cout<<sum<<endl;
    return 0;
}