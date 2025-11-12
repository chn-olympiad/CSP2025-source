#include<bits/stdc++.h>
using namespace std;

const int NP=5e5+10;
int n,k;
int a[NP],l,r,pre[NP],dp[NP],ans;
struct block{
    int l,r;
    bool operator <(const block & b ) const {
        if(l!=b.l) return l<b.l;
        return r<b.r;
    }
};
vector<block>v;

int dfs(vector<int> p,int r){
    int maxn=p.size();

    for(int i=0;i<v.size();i++){
        if(v[i].l>r){
            p.push_back(i);
            maxn=max(dfs(p,max(r,v[i].r)),maxn);
            p.pop_back();
        }
    }
    return maxn;
}


int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    pre[0]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==k){
            v.push_back({i,i});
        }
        pre[i]=a[i]^pre[i-1];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            if((pre[i]^pre[j-1])==k){
                v.push_back({j,i});
            }
        }
    }
    sort(v.begin(),v.end());
    vector<int> p;
    p.clear();
    cout<<dfs(p,0);
    return 0;
}
