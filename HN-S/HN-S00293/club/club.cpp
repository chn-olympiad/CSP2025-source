#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,a[N][3],cnt[3],sum;
vector<int>v[3];
void clear(){
    sum=0;
    for(int i=0;i<=2;i++){
        cnt[i]=0;
        v[i].clear();
    }
    return ;
}
void cg(int x){
    sort(v[x].begin(),v[x].end());
    int tot=0;
    for(int i=0;i<v[x].size();i++){
        sum-=v[x][i];
        ++tot;
        if(cnt[x]-tot==n/2) break;
    }
    cout<<sum<<'\n';
    return ;
}
void solve(){
    cin>>n;
    clear();
    for(int i=1;i<=n;i++){
        cin>>a[i][0]>>a[i][1]>>a[i][2]; 
        int mx=max(a[i][0],max(a[i][1],a[i][2]));
        sum+=mx;
        if(a[i][0]==mx){
            ++cnt[0];
            v[0].push_back(a[i][0]-max(a[i][1],a[i][2]));
        }
        else if(a[i][1]==mx){
            ++cnt[1];
            v[1].push_back(a[i][1]-max(a[i][0],a[i][2]));
        }
        else{
            ++cnt[2];
            v[2].push_back(a[i][2]-max(a[i][0],a[i][1]));
        }
    }
    if(cnt[0]<=n/2 && cnt[1]<=n/2 && cnt[2]<=n/2) cout<<sum<<'\n';
    if(cnt[0]>n/2) cg(0);
    if(cnt[1]>n/2) cg(1);
    if(cnt[2]>n/2) cg(2);
    return ;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--) solve();
    // cerr<<1e3*clock()/CLOCKS_PER_SEC<<"ms\n";
    return 0;
}