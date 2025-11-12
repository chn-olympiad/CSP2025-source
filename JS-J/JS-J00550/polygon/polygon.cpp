#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5010;
int dp[MAXN][MAXN];
int n,a[MAXN];
const int MOD=998244353;
vector<int> v;
bool check(){
    int maxm=0,sum=0;
    for(int i=0;i<v.size();i++){
        maxm=max(maxm,v[i]);
        sum+=v[i];
    }
    if(sum>maxm*2)return true;
    else return false;
}
int dfs(vector<int>::iterator be){
    if(v.size()<3)return 0;
    int res=0;
    if(check())res++;
    for(vector<int>::iterator i=be;i!=v.end();i++){
        int t=*i;
        vector<int>::iterator tbe=v.erase(i);
        res+=dfs(tbe);
        v.insert(i,t);
    }
    return res;
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        v.push_back(a[i]);
    }
    cout<<dfs(v.begin());
    return 0;
}