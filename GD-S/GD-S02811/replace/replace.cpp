#include <bits/stdc++.h>
using namespace std;
#define fo(i,l,r) for(int i=(l);i<=(r);++i)
#define fd(i,r,l) for(int i=(r);i>=(l);--i)
#define fu(i,l,r) for(int i=(l);i<(r);++i)
#define ll long long
#define ull unsigned long long
#define it128 __int128
#define vi vector<int>
#define pi pair<int,int>
#define fi first
#define se second
#define vp vector<pi>
#define pl pair<ll,ll>
#define eb emplace_back
#define Size(x) ((int)x.size())
const int N=2e5+5,ln=5e6+5;
int tr[ln][26],tot=0,fail[ln];
vi G[ln];
int dfn[ln],lst[ln],tdfn;
void dfs(int x) {
    dfn[x]=++tdfn;
    for(int v:G[x]) dfs(v);
    lst[x]=tdfn;
} 
int r1[N],r2[N],le[N];
char str[ln],str2[ln];
ll ans[N];
#define lowbit(x) (x&(-x))
struct BIT {
    int s[ln];
    void update(int x,int y) {while(x<=tdfn) s[x]+=y,x+=lowbit(x);}
    int query(int x) {int res=0; while(x) res+=s[x],x-=lowbit(x); return res;}
    void clear(int x) {while(x<=tdfn) s[x]=0,x+=lowbit(x);}
}bit;
int n,Q;
struct qryarr {int x,y,num;
    qryarr(const int &_x,const int &_y,const int &_num) :x(_x),y(_y),num(_num) {}
};
vector<qryarr> qry[ln],upd[ln];
void cdq(int l,int r) {
    if(l==r) return;
    int mid=(l+r)>>1;
    cdq(l,mid),cdq(mid+1,r);
    vector<qryarr> q,u;
    fo(i,l,mid) for(auto &j:qry[i]) q.eb(j);
    if(q.empty()) return;
    fo(i,mid+1,r) for(auto &j:upd[i]) u.eb(j);
    // cerr<<l<<' '<<r<<' '<<Size(q)<<' '<<Size(u)<<'\n';
    sort(q.begin(),q.end(),[](auto x,auto y) {return x.x<y.x;});
    sort(u.begin(),u.end(),[](auto x,auto y) {return x.x<y.x;});
    int t=0;
    for(auto &[x,y,num]:q) {
        while(t<Size(u)&&u[t].x<=x) {
            bit.update(u[t].y,u[t].num);
            ++t;
        }
        ans[num]+=bit.query(y);
    } 
    fu(i,0,Size(u)) bit.clear(u[i].y);
}
signed main() {
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>Q;
    int mxlen=0;
    fo(i,1,n) {
        scanf("%s",str+1);
        int len=strlen(str+1);
        le[i]=len;
        mxlen=max(mxlen,len);
        int x=0,c=0;
        fo(i,1,len) {
            c=str[i]-'a';
            if(!tr[x][c]) tr[x][c]=++tot;
            x=tr[x][c];
        }
        r1[i]=x;
        scanf("%s",str+1);
        x=0;
        fo(i,1,len) {
            c=str[i]-'a';
            if(!tr[x][c]) tr[x][c]=++tot;
            x=tr[x][c];
        }
        r2[i]=x;
    }
    queue<int> q;
    fu(i,0,26) if(tr[0][i]) q.push(tr[0][i]);
    while(Size(q)) {
        int u=q.front(); q.pop();
        fu(i,0,26) if(tr[u][i]) fail[tr[u][i]]=tr[fail[u]][i],q.push(tr[u][i]);
            else tr[u][i]=tr[fail[u]][i];
    }
    fo(i,1,tot) G[fail[i]].eb(i);
    dfs(0);
    fo(i,1,n) {
        upd[le[i]+1].eb(dfn[r1[i]],dfn[r2[i]],1);
        upd[le[i]+1].eb(dfn[r1[i]],lst[r2[i]]+1,-1);
        upd[le[i]+1].eb(lst[r1[i]]+1,dfn[r2[i]],-1);
        upd[le[i]+1].eb(lst[r1[i]]+1,lst[r2[i]]+1,1);
    }
    fo(Num,1,Q) {
        scanf("%s%s",str+1,str2+1);
        int m=strlen(str+1);
        if(strlen(str2+1)!=m) {ans[Num]=0; continue;}
        int pre=0,suf=m+1;
        while(pre+1<=m&&str[pre+1]==str2[pre+1]) ++pre;
        while(suf>1&&str[suf-1]==str2[suf-1]) --suf;
        int x=0,y=0;
        // cerr<<Q<<'\n';
        fo(i,1,m) {
            x=tr[x][str[i]-'a'],y=tr[y][str2[i]-'a'];
            if(i>=suf-1) qry[max(0,i-pre)].eb(dfn[x],dfn[y],Num);
        }
    }
    // cerr<<mxlen<<'\n';
    cdq(0,mxlen+1);
    fo(i,1,Q) printf("%lld\n",ans[i]);
}