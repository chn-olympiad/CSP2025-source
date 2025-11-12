#include<bits/stdc++.h>
using namespace std;
const int NR=1e5+5;
int T;
int n;
struct Node{
    pair<int,int> a[3];
};
vector<Node> f[3];
long long ans=0;
bool cmp(pair<int,int> a,pair<int,int> b){
    return a.second>b.second;
}
bool cmpN(Node a,Node b){
    return a.a[0].second-a.a[1].second>b.a[0].second-b.a[1].second;
}
void LCZ(int x){
    sort(f[x].begin(),f[x].end(),cmpN);
    for(int i=n/2;i<f[x].size();i++){
        Node t=f[x][i];
        ans-=t.a[0].second-t.a[1].second;
    }
}
void solve(){
    f[0].clear();
    f[1].clear();
    f[2].clear();
    scanf("%d",&n);
    ans=0;
    for(int i=1;i<=n;i++){
        Node t;
        for(int j=0;j<3;j++){
            int x;
            scanf("%d",&x);
            t.a[j]=make_pair(j,x);
        }
        sort(t.a,t.a+3,cmp);
        f[t.a[0].first].push_back(t);
        ans+=t.a[0].second;
    }
    if(f[0].size()>n/2) LCZ(0);
    else if(f[1].size()>n/2) LCZ(1);
    else if(f[2].size()>n/2) LCZ(2);
    printf("%lld\n",ans);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        solve();
    }
    return 0;
}
