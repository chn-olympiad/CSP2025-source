#include<bits/stdc++.h>
#define ull unsigned long long
#define rep(i,s,t) for(int i=s;i<=t;++i)
#define per(i,t,s) for(int i=t;i>=s;--i)
using namespace std;
template<typename T>
inline void read(T &x){
    int f=1;char c=getchar();x=0;
    for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}
const int N=2e5+10;
const ull base=573,MOD=998244353;
int n,Q;
string s[N][2],t[N][2];
int slen[N],tlen[N],id[N],idtim,l[N],r[N],ans[N];
ull sval[N],tval[N];
ull shash[N],thash[N];
map<ull,int> mp;
struct QUERY{
    int limitl,limitr,ansid;
};
vector<QUERY> q[N];
vector<pair<int,int> > pt[N],pts[N];
namespace BIT{
    int t[N];
    int lowbit(int x){return x&-x;}
    void clearr(int siz){
        rep(i,1,siz) t[i]=0;
    }
    void add(int siz,int x,int k){for(int i=x;i<=siz;i+=lowbit(i))t[i]+=k;}
    int SUM(int x){int res=0;for(int i=x;i;i-=lowbit(i))res+=t[i];return res;}
    int sum(int l,int r){return SUM(r)-SUM(l-1);}
}
vector<pair<pair<int,int>,int> > line;
int book[N],bcnt;
void solve(int ID){
    line.clear();bcnt=0;
    int siz=pt[ID].size();
    BIT::clearr(siz);
    if(siz==0) return;
    sort(pt[ID].begin(),pt[ID].end());
    rep(i,0,siz-1){
        line.push_back({{pt[ID][i].first,0},pt[ID][i].second});
        book[++bcnt]=pt[ID][i].second;
    }
    sort(book+1,book+bcnt+1);bcnt=unique(book+1,book+bcnt+1)-book-1;
    rep(i,0,(int)q[ID].size()-1){
        line.push_back({{q[ID][i].limitl,q[ID][i].ansid},q[ID][i].limitr});
    }
    sort(line.begin(),line.end());
    for(int i=0;i<(int)line.size();++i){
        //printf("%d %d %d\n",line[i].first.first,line[i].second,line[i].first.second);
        if(line[i].first.second!=0){
            ans[line[i].first.second]=BIT::SUM(upper_bound(book+1,book+bcnt+1,line[i].second)-book-1);
        }
        else{
            BIT::add(siz,lower_bound(book+1,book+bcnt+1,line[i].second)-book,1);
        }
    }
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    read(n);read(Q);
    rep(i,1,n){
        cin>>s[i][0]>>s[i][1];
        slen[i]=s[i][0].size();
        int diff_start=0,diff_end=slen[i]-1;
        rep(j,0,slen[i]-1){
            if(s[i][0][j]==s[i][1][j]) diff_start++;
            else break;
        }
        per(j,slen[i]-1,0){
            if(s[i][0][j]==s[i][1][j]) diff_end--;
            else break;
        }
        ull now=1;
        rep(j,diff_start,diff_end){
            shash[i]+=now*(s[i][0][j]-'a'+1);
            now*=base;
        }
        rep(j,diff_start,diff_end){
            shash[i]+=now*(s[i][1][j]-'a'+1);
            now*=base;
        }
        now=1;
        rep(j,0,slen[i]-1){
            sval[i]+=(s[i][0][j]-'a'+1)*(s[i][1][j]-'a'+1)*now;
            now*=base;
        }
        if(!mp[shash[i]]) mp[shash[i]]=++idtim;
        //mp[shash[i]]++;
        id[i]=mp[shash[i]];l[i]=diff_start;r[i]=slen[i]-diff_end-1;
        //printf("%d %d\n",l[i],r[i]);
        pt[id[i]].push_back({l[i],r[i]});
        //cout<<shash[i]<<"!"<<endl;
    }
    rep(i,1,Q){
        cin>>t[i][0]>>t[i][1];
        tlen[i]=t[i][0].size();
        int diff_start=0,diff_end=tlen[i]-1;
        rep(j,0,tlen[i]-1){
            if(t[i][0][j]==t[i][1][j]) diff_start++;
            else break;
        }
        per(j,tlen[i]-1,0){
            if(t[i][0][j]==t[i][1][j]) diff_end--;
            else break;
        }
        ull now=1;
        rep(j,diff_start,diff_end){
            thash[i]+=now*(t[i][0][j]-'a'+1);now*=base;
        }
        rep(j,diff_start,diff_end){
            thash[i]+=now*(t[i][1][j]-'a'+1);now*=base;
        }
        now=1;
        rep(j,0,tlen[i]-1){
            tval[i]+=(t[i][0][j]-'a'+1)*(t[i][1][j]-'a'+1)*now;
            now*=base;
        }
        l[i]=diff_start-0;r[i]=tlen[i]-diff_end-1;
        //cout<<l[i]<<" "<<r[i]<<endl;
        if(!mp[thash[i]]) continue;
        else q[mp[thash[i]]].push_back({l[i],r[i],i});
        //printf("%d\n",mp[thash[i]]);
        //cout<<thash[i]<<"!"<<endl;
    }
    rep(i,1,idtim) solve(i);
    rep(i,1,Q) printf("%d\n",ans[i]);
    return 0;
}
/*
*/
