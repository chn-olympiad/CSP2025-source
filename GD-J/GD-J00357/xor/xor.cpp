#include<bits/stdc++.h>
#include<vector>
using namespace std;
int n,k,a[100005],pre[100005];
struct node{
    int l,r;
    bool pd;
    const bool operator <(const node _) const{
        return l<_.l;
    }
};
vector<node> ans;
vector<node> g;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pre[i]=pre[i-1]^a[i];
    }//2 3 3 0
    for(int i=1;i<n;i++){
        for(int j=i;j<=n;j++){
            if(pre[i-1]^pre[j]==k) ans.push_back({i,j,1});
        }
    }
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans.size();j++){
            if(ans[i].l>=ans[j].l&&ans[i].r<=ans[j].r) ans[j].pd=false;
        }
    }
    for(int i=0;i<ans.size();i++){
        if(!ans[i].pd) g.push_back(ans[i]);
    }
    sort(g.begin(),g.end());
    int ans=1,r=a[1];
    for(int i=1;i<g.size();i++) if(g[i].l>r) ans++,r=g[i].r;
    cout<<ans;
    return 0;
}
