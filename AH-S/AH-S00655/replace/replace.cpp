#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define up(i,a,b) for (int i=(a);i<=(b);i++)
#define down(i,a,b) for (int i=(a);i>=(b);i--)
using namespace std;

bool st;

const int N=2e5+5,L=5e6+5;
const ull base=137;
int n,q;

string s1[N],s2[N],t1[N],t2[N];

int sl[N],sr[N],tl[N],tr[N];
ull s1y[N],s2y[N],t1y[N],t2y[N];

#define puu pair<ull,ull>
map<puu,vector<int>> mps,mpt;


struct ACAM{
    struct node{
        int ch[28];
        int fail,cnt;
    }tr[L];
    int idx;

    vector<int> g[L];
    int lk[L];
    void add(int u,int v){g[u].emplace_back(v);lk[v]++;}

    void clear(){
        up(i,0,idx){
            up(j,0,26){
                tr[i].ch[j]=0;
            }
            tr[i].fail=0;
            tr[i].cnt=0;
            lk[i]=0;
            g[i].clear();
        }
        idx=0;
    }
    void ins(string &s){
        int now=0;
        up(i,0,s.length()-1){
            int &nxt=tr[now].ch[s[i]-'a'];
            if (!nxt) nxt=++idx;
            now=nxt;
        }
        tr[now].cnt++;
    }

    void getfail(){
        queue<int> q;
        up(i,0,26){
            if (tr[0].ch[i]){
                q.push(tr[0].ch[i]);
            }
        }
        while (!q.empty()){
            int u=q.front();q.pop();
            int pre=tr[u].fail;
            up(i,0,26){
                int v=tr[u].ch[i];
                if (v){
                    tr[v].fail=tr[pre].ch[i];
                    q.push(v);
                }
                else tr[u].ch[i]=tr[pre].ch[i];
            }
        }
        up(i,1,idx) add(tr[i].fail,i);
    }
    void topo(){
        queue<int> q;
        up(i,0,idx) if (!lk[i]) q.push(i);
        while (!q.empty()){
            int u=q.front();q.pop();
            for (int v:g[u]){
                tr[v].cnt+=tr[u].cnt;
                if (!--lk[v]) q.push(v);
            }
        }
    }
    int dfs(string &s){
        int now=0,rt=0;
        up(i,0,s.length()-1){
            while (now&&tr[now].ch[s[i]-'a']==0) now=tr[now].fail;
            now=tr[now].ch[s[i]-'a'];
            rt+=tr[now].cnt;
        }
        return rt;
    }

}M;

int ans[N];

void solve(vector<int> &s,vector<int>&t){
//    cout<<" gooo\n";
//    for (int x:s) cout<<x<<' ';
//    cout<<'\n';
//    for (int x:t) cout<<x<<' ';
//    cout<<'\n';
    M.clear();
    for (int x:s){
        string res;
        up(i,0,sl[x]-1) res+=s1[x][i];
        res+='z'+1;
        up(i,sr[x]+1,s1[x].length()-1) res+=s1[x][i];
        M.ins(res);
//        cout<<" checksss "<<res<<'\n';
    }
    M.getfail(),M.topo();
    for (int x:t){
        string res;
        up(i,0,tl[x]-1) res+=t1[x][i];
        res+='z'+1;
        up(i,tr[x]+1,t1[x].length()-1) res+=t1[x][i];
//        cout<<" checkttt "<<res<<'\n';
        ans[x]+=M.dfs(res);
    }
}

bool ed;
int main(){
//    cerr<<(&ed-&st)/1024.0/1024.0<<'\n';
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>q;
    up(i,1,n) cin>>s1[i]>>s2[i];
    up(i,1,q) cin>>t1[i]>>t2[i];
    up(i,1,n){
        int len=s1[i].length();
        while (sl[i]<len&&s1[i][sl[i]]==s2[i][sl[i]]) sl[i]++;
        sr[i]=len-1;
        while (sr[i]>-1&&s1[i][sr[i]]==s2[i][sr[i]]) sr[i]--;
//        cout<<sl[i]<<' '<<sr[i]<<'\n';

        up(j,sl[i],sr[i]){
            s1y[i]=s1y[i]*base+s1[i][j];
            s2y[i]=s2y[i]*base+s2[i][j];
        }

        puu k={s1y[i],s2y[i]};
        mps[k].emplace_back(i);

//        cout<<s1y[i]<<' '<<s2y[i]<<'\n';
    }
    up(i,1,q){
        if (t1[i].length()!=t2[i].length()){
            ans[i]=0;
            continue;
        }
        int len=t1[i].length();
        while (tl[i]<len&&t1[i][tl[i]]==t2[i][tl[i]]) tl[i]++;
        tr[i]=len-1;
        while (tr[i]>-1&&t1[i][tr[i]]==t2[i][tr[i]]) tr[i]--;
//        cout<<tl[i]<<' '<<tr[i]<<'\n';

        up(j,tl[i],tr[i]){
            t1y[i]=t1y[i]*base+t1[i][j];
            t2y[i]=t2y[i]*base+t2[i][j];
        }

        puu k={t1y[i],t2y[i]};
        mpt[k].emplace_back(i);

//        cout<<t1y[i]<<' '<<t2y[i]<<'\n';
    }

    for (auto &k:mpt){
        auto kk=k.first;
        if (!mps.count(kk)) continue;
        solve(mps[kk],k.second);
    }

    up(i,1,q) cout<<ans[i]<<'\n';

    return 0;
}
