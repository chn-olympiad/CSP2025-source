#include<bits/stdc++.h>
using namespace std;
namespace mycode{
    typedef unsigned long long ull;
    const ull mod[2]={998244353,1000000007};
    const ull base[2]={37,41};
    int n,q;
    string s[200005][2];
    int l[200005],r[200005];
    ull hshz[200005][2][2];
    ull hshw[200005][2];
    int dyz[200005],dyzl;
    int dyw[200005],dywl;
    map<pair<pair<ull,ull>,pair<ull,ull> >,int> dyzmp; 
    map<pair<ull,ull>,int> dywmp; 
    namespace segtree{
        #define ls son[u][0]
        #define rs son[u][1]
        int f[4000005];
        int son[4000005][2];
        int fl;
        void update(int&u,int w,int l=1,int r=dywl){
            if(!u) u=++fl;
            if(l==r){f[u]++;return;}
            int mid=(l+r)>>1;
            if(w<=mid) update(ls,w,l,mid);
            else update(rs,w,mid+1,r);
        }
        void merge(int&u,int v,int l=1,int r=dywl){
            if(!u){u=v;return;}
            if(!v) return;
            if(l==r){f[u]+=f[v];return;}
            int mid=(l+r)>>1;
            merge(ls,son[v][0],l,mid);
            merge(rs,son[v][1],mid+1,r);
        }
        int query(int u,int w,int l=1,int r=dywl){
            if(!u) return 0;
            if(l==r) return f[u];
            int mid=(l+r)>>1;
            if(w<=mid) return query(ls,w,l,mid);
            return query(rs,w,mid+1,r);
        }
    }
    int rt[200005];
    vector<int> vl[5000005];
    int segrt[5000005];
    int son[5000005][26];
    int trl;
    void dfs(int u,int fa){
        for(auto i:vl[u]) segtree::update(segrt[u],i);
        segtree::merge(segrt[u],segrt[fa]);
        for(int i=0;i<26;i++) if(son[u][i]) dfs(son[u][i],u);
    }
    string t[2];
    int tl,tr;
    int tdyz,tdyw;
    ull thshz[2][2];
    ull thshw[2];
    void solve(){
        cin>>n>>q;
        for(int i=1;i<=n;i++) cin>>s[i][0]>>s[i][1];
        for(int i=1;i<=n;i++){
            int m=s[i][0].size();
            for(int j=0;j<m;j++){if(s[i][0][j]!=s[i][1][j]){break;}l[i]++;}
            for(int j=m-1;j>=0;j--){if(s[i][0][j]!=s[i][1][j]){break;}r[i]++;} 
            for(int j=l[i];j<m-r[i];j++){
                hshz[i][0][0]=(hshz[i][0][0]*base[0]+s[i][0][j]-'a'+1)%mod[0];
                hshz[i][0][1]=(hshz[i][0][1]*base[1]+s[i][0][j]-'a'+1)%mod[1];
                hshz[i][1][0]=(hshz[i][1][0]*base[0]+s[i][1][j]-'a'+1)%mod[0];
                hshz[i][1][1]=(hshz[i][1][1]*base[1]+s[i][1][j]-'a'+1)%mod[1];
            }
            if(dyzmp[{{hshz[i][0][0],hshz[i][0][1]},{hshz[i][1][0],hshz[i][1][1]}}]==0){
                dyzmp[{{hshz[i][0][0],hshz[i][0][1]},{hshz[i][1][0],hshz[i][1][1]}}]=++dyzl;
                dyz[i]=dyzl;
            }
            else dyz[i]=dyzmp[{{hshz[i][0][0],hshz[i][0][1]},{hshz[i][1][0],hshz[i][1][1]}}];
            for(int j=m-r[i];j<m;j++){
                hshw[i][0]=(hshw[i][0]*base[0]+s[i][0][j]-'a'+1)%mod[0];   
                hshw[i][1]=(hshw[i][1]*base[1]+s[i][0][j]-'a'+1)%mod[1];   
            }
            if(dywmp[{hshw[i][0],hshw[i][1]}]==0){
                dywmp[{hshw[i][0],hshw[i][1]}]=++dywl;
                dyw[i]=dywl;
            }
            else dyw[i]=dywmp[{hshw[i][0],hshw[i][1]}];
            int*u=&rt[dyz[i]];
            for(int j=l[i]-1;j>=0;j--){
                if(!(*u)) (*u)=++trl;
                u=&son[*u][s[i][0][j]-'a'];
            }
            if(!(*u)) (*u)=++trl;
            vl[*u].push_back(dyw[i]);
        }
        for(int i=1;i<=dyzl;i++) if(rt[i]) dfs(rt[i],0);
        while(q--){
            cin>>t[0]>>t[1];
            if(t[0].size()!=t[1].size()){printf("0\n");continue;}
            int m=t[0].size();
            tl=tr=0;
            for(int j=0;j<m;j++){if(t[0][j]!=t[1][j]){break;}tl++;}
            for(int j=m-1;j>=0;j--){if(t[0][j]!=t[1][j]){break;}tr++;}
            thshz[0][0]=thshz[0][1]=thshz[1][0]=thshz[1][1]=0;
            for(int j=tl;j<m-tr;j++){
                thshz[0][0]=(thshz[0][0]*base[0]+t[0][j]-'a'+1)%mod[0];
                thshz[0][1]=(thshz[0][1]*base[1]+t[0][j]-'a'+1)%mod[1];
                thshz[1][0]=(thshz[1][0]*base[0]+t[1][j]-'a'+1)%mod[0];
                thshz[1][1]=(thshz[1][1]*base[1]+t[1][j]-'a'+1)%mod[1];
            }
            if(dyzmp.count({{thshz[0][0],thshz[0][1]},{thshz[1][0],thshz[1][1]}})==0){printf("0\n");continue;}
            else tdyz=dyzmp[{{thshz[0][0],thshz[0][1]},{thshz[1][0],thshz[1][1]}}];
            int u=rt[tdyz];
            for(int j=tl-1;j>=0;j--){
                if(!son[u][t[0][j]-'a']) break;
                u=son[u][t[0][j]-'a'];
            }
            thshw[0]=thshw[1]=0;
            int ans=0;
            if(dywmp.count({thshw[0],thshw[1]})){
                tdyw=dywmp[{thshw[0],thshw[1]}];
                ans+=segtree::query(segrt[u],tdyw);
            }
            for(int j=m-tr;j<m;j++){
                thshw[0]=(thshw[0]*base[0]+t[0][j]-'a'+1)%mod[0];
                thshw[1]=(thshw[1]*base[1]+t[0][j]-'a'+1)%mod[1];
                if(dywmp.count({thshw[0],thshw[1]})){
                    tdyw=dywmp[{thshw[0],thshw[1]}];
                    ans+=segtree::query(segrt[u],tdyw);
                }
            }
            printf("%d\n",ans);
        }
    }
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    mycode::solve();
    return 0;
}