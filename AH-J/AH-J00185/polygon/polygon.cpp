#include<bits/stdc++.h>

using namespace std;
int n,a[5005],cnt;
bool vis[5005];
set<int> st;
set<set<int>> stt;
bool check(set<int> &st){
    if(stt.count(st)){
        return false;
    }
    int maxn=0;
    long long sum=0;
    for(int x:st){
        maxn=max(maxn,a[x]);
        sum+=a[x];
    }
    return sum>2*maxn;
}
void dfs(int p){
    vis[p]=true;
    st.insert(p);
    if(st.size()>3){
        if(check(st)){
            cnt++;
            stt.insert(st);
            //for(int x:st){
            //    cout<<x<<" ";
            //}
            //cout<<endl;
        }
        cnt%=998244353;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            //cout<<i<<" ";
            //for(int x:st){
            //    cout<<x<<" ";
            //}
            //cout<<endl;
            dfs(i);
        }
    }
    vis[p]=false;
    st.erase(p);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(0);
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
