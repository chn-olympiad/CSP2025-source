#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2e5+114;
const int maxL = 5e6+2e5+114;
string s1[maxn],s2[maxn];
string t1[maxn],t2[maxn];
//异同对齐
const ll mod = 998244353;
const ll base = 1331;
ll val[maxn][2];
int n,q;
int tot1;
int ch1[maxL][26];
vector<int> info[maxL],ask[maxL];
int root2;
int tot2;
int ch2[maxL][26];
int cnt[maxL];
map<ll,int> root1;
int l[maxn],r[maxn];
int L[maxn],R[maxn];
int ans[maxn];
void dfs(int u){
    for(int id:info[u]){
        int x=root2;
        bool flag=true;
        for(int i=l[id]-1;i>=0;i--){
            if(ch2[x][s1[id][i]-'a']==0){
                flag=false;
                break;
            }
            x=ch2[x][s1[id][i]-'a'];
        }
        if(flag==false) continue;
        cnt[x]++;
    }
    for(int id:ask[u]){
        int x=root2;
        ans[id]+=cnt[x];
        for(int i=L[id]-1;i>=0;i--){
            x=ch2[x][t1[id][i]-'a'];
            ans[id]+=cnt[x];
        }
    }
    for(int i=0;i<26;i++){
        if(ch1[u][i]!=0) dfs(ch1[u][i]);
    }
    for(int id:info[u]){
        int x=root2;
        bool flag=true;
        for(int i=l[id]-1;i>=0;i--){
            if(ch2[x][s1[id][i]-'a']==0){
                flag=false;
                break;
            }
            x=ch2[x][s1[id][i]-'a'];
        }
        if(flag==false) continue;
        cnt[x]--;
    }    
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
    for(int i=1;i<=q;i++){
        cin>>t1[i]>>t2[i];
        if(t1[i].size()!=t2[i].size()) continue;
        int len=t1[i].size();
        L[i]=len,R[i]=-1;
        for(int j=0;j<len;j++){
            if(t1[i][j]!=t2[i][j]) L[i]=min(L[i],j),R[i]=max(R[i],j);
        }
        if(L[i]<=R[i]){
            ll res=0;
            for(int j=L[i];j<=R[i];j++){
                res=(res*base+(t1[i][j]-'a')*26+(t2[i][j]-'a')+1)%mod;
            }
            if(root1[res]==0) root1[res]=++tot1;
            int u=root1[res];
            for(int j=R[i]+1;j<len;j++){
                if(ch1[u][t1[i][j]-'a']==0) ch1[u][t1[i][j]-'a']=++tot1;
                u=ch1[u][t1[i][j]-'a'];
            }
            ask[u].push_back(i);
        }
    }
    for(int i=1;i<=n;i++){
        int len=s1[i].size();
        l[i]=len,r[i]=-1;
        for(int j=0;j<len;j++){
            if(s1[i][j]!=s2[i][j]) l[i]=min(l[i],j),r[i]=max(r[i],j);
        }
        if(l[i]<=r[i]){
            ll res=0;
            for(int j=l[i];j<=r[i];j++){
                res=(res*base+(s1[i][j]-'a')*26+(s2[i][j]-'a')+1)%mod;
            }
            if(root1[res]==0){
                continue;
            }
            int u=root1[res];
            bool flag=true;
            for(int j=r[i]+1;j<len;j++){
                if(ch1[u][s1[i][j]-'a']==0){
                    flag=false;
                    break;
                }
                u=ch1[u][s1[i][j]-'a'];
            }
            if(flag==false) continue;
            info[u].push_back(i);
        }
    }
    root2=++tot2;
    for(int i=1;i<=q;i++){
        int x=root2;
        for(int j=L[i]-1;j>=0;j--){
            if(ch2[x][t1[i][j]-'a']==0) ch2[x][t1[i][j]-'a']=++tot2;
            x=ch2[x][t1[i][j]-'a'];
        }
    }
    for(pair<ll,int> now:root1) dfs(now.second);
    for(int i=1;i<=q;i++) cout<<ans[i]<<"\n";
    return 0;
}
/*
2 1
xabcx xadex
bc de
xabcx xadex
*/