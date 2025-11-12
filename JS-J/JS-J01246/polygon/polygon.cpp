#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,v,cnt;
vector<int> a;
void dfs(int x,int sum,int mx){
    if(x>n){
        return;
    }
    int sumt=sum+a[x],mxt=max(mx,a[x]);
    if(sumt>mxt*2){
        ++cnt;
        if(cnt>=mod){
            cnt-=mod;
        }
    }
    dfs(x+1,sumt,mxt);
    dfs(x+2,sumt,mxt);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    a.push_back(0);
    for(int i=1;i<=n;++i){
        cin>>v;
        a.push_back(v);
    }
    for(int i=1;i<=n;++i){
        dfs(i,0,0);
    }
    cout<<cnt<<endl;
    return 0;
}
