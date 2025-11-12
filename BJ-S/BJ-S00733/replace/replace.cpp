#include<bits/stdc++.h>
using namespace std;
namespace compile{
    void begin(){
        #ifdef DOWN
            FILE *fp_in=freopen("replace3.in","r",stdin);
            FILE *fp_out=freopen("out","w",stdout);
        #else
            FILE *fp_in=freopen("replace.in","r",stdin);
            FILE *fp_out=freopen("replace.out","w",stdout);
        #endif
        ios::sync_with_stdio(0);
        return ;
    }
    void end(){
        #ifdef TIME
            cerr<<"程序运行时间:"<<1.0*clock()/CLOCKS_PER_SEC<<"秒"<<endl;
        #endif
        return ;
    }
}
#define ll long long
#define bs bitset<M>
const int N=2e5+5,M=5e6+5,K=26;
int n,q,cnt[2];
string s[2],t[2];
int son[2][M][K];
int fail[2][M][K];
int fa[2][M],c[2][M];
int len[2][M],d[2][M];//d:id
void add(bool f,int id,string &str){
    int now=0;
    for(int i=0,j;i<str.size();i++){
        j=str[i]-'a';
        if(!son[f][now][j]){
            son[f][now][j]=++cnt[f];
            fa[f][cnt[f]]=now;
            c[f][cnt[f]]=j;
            //cerr<<now<<"->("<<cnt[f]<<','<<(char)(j+'a')<<')'<<endl;
        }
        now=son[f][now][j];
    }
    len[f][now]=str.size();
    d[f][now]=id;
    return ;
}
void make_fail(bool f){
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int i=q.front();q.pop();
        for(int j=0;j<K;j++){
            if(i)fail[f][i][j]=son[f][fail[f][fa[f][i]][c[f][i]]][j] ? son[f][fail[f][fa[f][i]][c[f][i]]][j] : fail[f][fail[f][fa[f][i]][c[f][i]]][j];
            if(son[f][i][j]){
                q.push(son[f][i][j]);
            }
        }
    }
    return ;
}
void init(){
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        for(int j=0;j<2;j++){
            cin>>s[j];
            add(j,i,s[j]);
        }
    }
    make_fail(0);
    make_fail(1);
    return ;
}
#define pr pair<int,int>

map<pr,bool> ct;
int fd(bool f,string &str,int b,int e){
    //cerr<<f<<':'<<b<<' '<<e<<endl;
    int now=0,ans=0;
    for(int i=1;i<str.size();i++){
        //cerr<<i<<' '<<str[i]<<':'<<now;
        int j=str[i]-'a';
        if(son[f][now][j])now=son[f][now][j];
        else now=fail[f][now][j];
        //cerr<<"->"<<now<<':';
        int o=now;
        do{
            //cerr<<o<<' ';
            if(len[f][o] and e<=i and i-len[f][o]+1<=b){
                if(!f){
                    ct[pr(d[f][o],i)]=1;
                }else{
                    if(ct.count(pr(d[f][o],i)))ans++;
                }
            }
            o=fail[f][fa[f][o]][c[f][o]];
        }while(o);
        //cerr<<endl;
    }
    //cerr<<endl;
    return ans;
}
void work(){
    while(q--){
        ct.clear();
        cin>>t[0]>>t[1];
        if(t[0].size()!=t[1].size()){
            cout<<0<<'\n';
            continue;
        }else{
            t[0]=' '+t[0];
            t[1]=' '+t[1];
            int b,e,l;
            l=t[0].size();
            for(b=0;b<=l and t[0][b]==t[1][b];b++);
            for(e=l+1;e>=1 and t[0][e]==t[1][e];e--);
            //cout<<t[0]<<endl<<t[1]<<endl<<b<<' '<<e<<endl<<endl;
            fd(0,t[0],b,e);
            cout<<fd(1,t[1],b,e)<<'\n';
        }
    }
    return ;
}
signed main(){
    compile::begin();
    init();
    work();
    compile::end();
    return 0;
}