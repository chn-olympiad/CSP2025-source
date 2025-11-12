#include<bits/stdc++.h>
#define reg register
#define int long long
#define mp make_pair
#define pi pair<int,int>
#define il inline
using namespace std;
il int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9')f=(ch=='-'?-1:f),ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+(ch-'0'),ch=getchar();
    return x*f;
}
bool B;
const int Base=821,mod1=1e9+7,mod2=998244353;
const int N=2e5+5,M=5e6+5,T=5e6+5;
int n,Q,l[N*2],r[N*2];
pair<pair<pi,pi >,int>w[N*2];
string s1[N],s2[N],t1[N],t2[N];
int col[N*2],rot[N*2][2];
vector<int>ton[T+N*10],sta;
bool vis[N];
int ch[T+N*10][26],tot;
bool E;
signed main(){
    //cerr<<(&E-&B)/1048576.0<<'\n';
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    n=read(),Q=read();
    for(reg int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
        int len=s1[i].length();
        while(s1[i][l[i]]==s2[i][l[i]])
            l[i]++;
        r[i]=len-1;
        while(s1[i][r[i]]==s2[i][r[i]])
            r[i]--;
        r[i]+=2;
        int hs01=0,hs11=0,hs02=0,hs12=0;
        for(reg int j=l[i]+1;j<r[i];j++){
            hs01=(hs01*Base%mod1+(int)(s1[i][j-1]-'a'))%mod1;
            hs11=(hs11*Base%mod2+(int)(s1[i][j-1]-'a'))%mod2;
            hs02=(hs02*Base%mod1+(int)(s2[i][j-1]-'a'))%mod1;
            hs12=(hs12*Base%mod2+(int)(s2[i][j-1]-'a'))%mod2;
        }
        w[i]=mp(mp(mp(hs01,hs11),mp(hs02,hs12)),i);
    }
    for(reg int i=1;i<=Q;i++){
        cin>>t1[i]>>t2[i];
        int len=t1[i].length();
        if(t2[i].length()!=len)
            continue;
        while(t1[i][l[i+n]]==t2[i][l[i+n]])
            l[i+n]++;
        r[i+n]=len-1;
        while(t1[i][r[i+n]]==t2[i][r[i+n]])
            r[i+n]--;
        r[i+n]+=2;
        int hs01=0,hs11=0,hs02=0,hs12=0;
        for(reg int j=l[i+n]+1;j<r[i+n];j++){
            hs01=(hs01*Base%mod1+(int)(t1[i][j-1]-'a'))%mod1;
            hs11=(hs11*Base%mod2+(int)(t1[i][j-1]-'a'))%mod2;
            hs02=(hs02*Base%mod1+(int)(t2[i][j-1]-'a'))%mod1;
            hs12=(hs12*Base%mod2+(int)(t2[i][j-1]-'a'))%mod2;
        }
        w[i+n]=mp(mp(mp(hs01,hs11),mp(hs02,hs12)),i+n);
    }
    sort(w+1,w+1+n+Q);
    int cnt=0;
    for(reg int i=1;i<=n+Q;i++){
        if(i==1||w[i].first!=w[i-1].first)
            cnt++;
        col[w[i].second]=cnt;
    }
    for(reg int i=1;i<=cnt;i++){
        rot[i][0]=++tot;
        rot[i][1]=++tot;
    }
    for(reg int i=1;i<=n;i++){
        int len=s1[i].length();
        int now=rot[col[i]][0];
        for(reg int j=l[i];j>0;j--){
            int c=(int)(s1[i][j-1]-'a');
            if(!ch[now][c])
                ch[now][c]=++tot;
            now=ch[now][c];
        }
        ton[now].push_back(i);
        now=rot[col[i]][1];
        for(reg int j=r[i];j<=len;j++){
            int c=(int)(s1[i][j-1]-'a');
            if(!ch[now][c])
                ch[now][c]=++tot;
            now=ch[now][c];
        }
        ton[now].push_back(i);
    }
    for(reg int i=1;i<=Q;i++){
        int res=0;
        int len=t1[i].length();
        if(t2[i].length()!=len){
            cout<<"0\n";
            continue;
        }
        int now=rot[col[i+n]][0];
        sta.clear();
        for(auto v:ton[now]){
            sta.push_back(v);
            vis[v]=1;
        }
        for(reg int j=l[i+n];j>0;j--){
            int c=(int)(t1[i][j-1]-'a');
            if(!ch[now][c])break;
            now=ch[now][c];
            for(auto v:ton[now]){
                sta.push_back(v);
                vis[v]=1;
            }
        }
        now=rot[col[i+n]][1];
        for(auto v:ton[now])
            if(vis[v])res++;
        for(reg int j=r[i+n];j<=len;j++){
            int c=(int)(t1[i][j-1]-'a');
            if(!ch[now][c])break;
            now=ch[now][c];
            for(auto v:ton[now])
                if(vis[v])res++;
        }
        cout<<res<<'\n';
        for(auto v:sta)
            vis[v]=0;
    }
    return 0;
}
