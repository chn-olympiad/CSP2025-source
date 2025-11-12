#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

typedef long long i64;

const int lim=2.5e6;
const i64 m1=1921072319;
const i64 m2=1949100103;
const i64 b1=131;
const i64 b2=1331;

int pw1[lim+5];
int pw2[lim+5];

struct node{
    int h1,h2,len;
    friend inline node operator+(const node &x,const node &y){
        return{(int)((1ll*x.h1*pw1[y.len]+y.h1)%m1),(int)((1ll*x.h2*pw2[y.len]+y.h2)%m2),x.len+y.len};
    }
    friend inline node operator-(const node &x,const node &y){
        return{(int)((x.h1-1ll*y.h1*pw1[x.len-y.len]%m1+m1)%m1),(int)((x.h2-1ll*y.h2*pw2[x.len-y.len]%m2+m2)%m2),x.len-y.len};
    }
    friend inline bool operator==(const node &x,const node &y){
        return x.h1==y.h1&&x.h2==y.h2;
    }
};
struct hs_type{
    inline int operator()(const node &x)const{
        return x.h2;
    }
};

int n,q;
string s[200005][2];
string t[200005][2];
vector<node>h[200005][2];
int L[200005];
int R[200005];
node hs1[lim+5];
node hs2[lim+5];
unordered_map<node,vector<int>,hs_type>mp[lim+5];

static inline bool isok(const string &str){
    bool fl=false;
    for(auto c:str){
        if(c>'b')
            return false;
        if(c=='b'){
            if(fl)
                return false;
            fl=true;
        }
    }
    return true;
}

int c[lim+5];
int tm[lim+5],stp;
static inline int lowbit(int x){return x&(-x);}
static inline void add(int x,int w){
    while(x<=lim){
        if(tm[x]!=stp){
            tm[x]=stp;
            c[x]=0;
        }
        c[x]+=w;
        x+=lowbit(x);
    }
}
static inline int query(int x){
    int ret=0;
    while(x){
        if(tm[x]==stp)
            ret+=c[x];
        x-=lowbit(x);
    }
    return ret;
}
unordered_map<node,vector<pair<pair<int,int>,int>>,hs_type>qs[lim+5];
int ans[200005];

signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    pw1[0]=pw2[0]=1;
    for(int i=1;i<=lim;++i){
        pw1[i]=1ll*pw1[i-1]*b1%m1;
        pw2[i]=1ll*pw2[i-1]*b2%m2;
    }
    cin>>n>>q;
    bool ok=true;
    for(int i=1;i<=n;++i){
        cin>>s[i][0]>>s[i][1];
        if(ok)
            ok=isok(s[i][0]);
        if(ok)
            ok=isok(s[i][1]);
        s[i][0]=' '+s[i][0];
        s[i][1]=' '+s[i][1];
        h[i][0].resize(s[i][0].size());
        h[i][1].resize(s[i][1].size());
        h[i][0][0]=h[i][1][0]={0,0,0};
        int l=0,r=0;
        for(int j=1;j<(int)s[i][0].size();++j){
            h[i][0][j]=h[i][0][j-1]+node{s[i][0][j],s[i][0][j],1};
            h[i][1][j]=h[i][1][j-1]+node{s[i][1][j],s[i][1][j],1};
            if(s[i][0][j]!=s[i][1][j]){
                if(!l)
                    l=j;
                r=j;
            }
        }
        if(l){
            L[i]=l;
            R[i]=r;
            node hs=(h[i][0][r]-h[i][0][l-1])+(h[i][1][r]-h[i][1][l-1]);
            mp[r-l][hs].push_back(i);
        }
    }
    for(int i=1;i<=q;++i){
        cin>>t[i][0]>>t[i][1];
        if(ok)
            ok=isok(t[i][0]);
        if(ok)
            ok=isok(t[i][1]);
    }
    if(ok){
        for(int _=1;_<=q;++_){
            string t1=t[_][0];
            string t2=t[_][1];
            if(t1.size()!=t2.size()){
                cout<<"0\n";
                continue;
            }
            int m=(int)t1.size();
            t1=' '+t1;
            t2=' '+t2;
            int l=0,r=0;
            for(int i=1;i<=m;++i){
                hs1[i]=hs1[i-1]+node{t1[i],t1[i],1};
                hs2[i]=hs2[i-1]+node{t2[i],t2[i],1};
                if(t1[i]!=t2[i]){
                    if(!l)
                        l=i;
                    r=i;
                }
            }
            node hs=(hs1[r]-hs1[l-1])+(hs2[r]-hs2[l-1]);
            qs[r-l][hs].push_back({{l,m-r},_});
        }
        for(int len=0;len<=lim;++len){
            for(auto &p:qs[len]){
                vector<int>vec=mp[len][p.first];
                vector<pair<pair<int,int>,int>>qq=p.second;
                sort(vec.begin(),vec.end(),[](int x,int y){return L[x]<L[y];});
                sort(qq.begin(),qq.end(),[](const pair<pair<int,int>,int>& x,const pair<pair<int,int>,int>& y){return x.first.first<y.first.first;});
                ++stp;
                int i=0;
                for(auto lq:qq){
                    while(i<(int)vec.size()&&L[vec[i]]<=lq.first.first){
                        add((int)s[vec[i]][0].size()-R[vec[i]],1);
                        ++i;
                    }
                    ans[lq.second]=query(lq.first.second+1);
                }
            }
        }
        for(int i=1;i<=q;++i)
            cout<<ans[i]<<'\n';
        return 0;
    }
    for(int _=1;_<=q;++_){
        string t1=t[_][0];
        string t2=t[_][1];
        if(t1.size()!=t2.size()){
            cout<<"0\n";
            continue;
        }
        int m=(int)t1.size();
        t1=' '+t1;
        t2=' '+t2;
        int l=0,r=0;
        for(int i=1;i<=m;++i){
            hs1[i]=hs1[i-1]+node{t1[i],t1[i],1};
            hs2[i]=hs2[i-1]+node{t2[i],t2[i],1};
            if(t1[i]!=t2[i]){
                if(!l)
                    l=i;
                r=i;
            }
        }
        node hs=(hs1[r]-hs1[l-1])+(hs2[r]-hs2[l-1]);
        int ret=0;
        for(auto x:mp[r-l][hs]){
            int lb=L[x]-1;
            int rb=(int)s[x][0].size()-R[x]-1;
            if(l<=lb||m-r<rb)
                continue; // 放不下
            if(h[x][0][s[x][0].size()-1]-h[x][0][R[x]]==hs1[r+rb]-hs1[r]){
                if(h[x][0][L[x]-1]==hs1[l-1]-hs1[l-lb-1]){
                    ++ret;
                }
            }
        }
        cout<<ret<<'\n';
    }
    return 0;
}