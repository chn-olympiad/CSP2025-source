#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int N=5e6+15,M=1e6+5;
bool ST;
int n,q;
string s,t;
struct node{
    vector<pii> to;
}tr[N];
int tot=1;
int fa[N],cnt[N],dep[N];
int check(int x,int c){
    for(pii now:tr[x].to) {
        if(now.first==c) return now.second;
    }
    return -1;
}
int insert(int x,int c){
    for(pii now:tr[x].to) {
        if(now.first==c) {
            return now.second;
        }
    }
    tr[x].to.push_back({c,++tot});
    int j=fa[x];
    while(check(j,c)==-1&&j) j=fa[j];
    if(!j) j=1;
    else {
        int k=check(j,c);
        if(k!=-1) j=k;
    }
    fa[tot]=j;dep[tot]=dep[x]+1;
    return tot;
}
int get(int x,int k){
    int res=0;
    while(dep[x]>=k) res+=cnt[x],x=fa[x];
    return res;    
}
struct LR{
    string sc,tc;
    int now,lst;
    void add(){
        int c=(sc[now]-'a')*26+(tc[now]-'a');
        lst=insert(lst,c);
        now++;
    }
}a[N];
bool ED;
signed main(){
    // cerr<<(&ED-&ST)/1048576.0<<'\n';
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++) {
        cin>>a[i].sc>>a[i].tc;
    }
    sort(a+1,a+n+1,[](LR x,LR y){return x.sc.length()<y.sc.length();});
    int dq=1;
    while(dq<=n){
        for(int j=dq;j<=n;j++) {
            a[j].add();
            if(a[j].now==a[j].sc.length()) {
                cnt[a[j].lst]++;
                dq++;
            }
        }
    }
    while(q--) {
        cin>>s>>t;
        if(s.length()!=t.length()) {
            cout<<0<<'\n';
            continue;
        }
        int l=-1,r,m=s.length();
        for(int i=0;i<m;i++) {
            if(s[i]!=t[i]){
                if(l==-1) l=i;
                r=i;
            } 
        }
        // cerr<<l<<' '<<r<<'\n';
        // continue; 
        int now=1,ans=0;
        for(int i=0;i<m;i++) {
            int c=(s[i]-'a')*26+(t[i]-'a');
            while(check(now,c)==-1&&now) now=fa[now];
            if(!now) now=1;
            else now=check(now,c);
            if(i>=r) {
                int res=get(now,i-l+1);
                ans+=res;
                // if(!res) break;
            }
            // cerr<<now<<' ';
        }
        // cerr<<'\n';
        cout<<ans<<'\n';
    }
    return 0;
}