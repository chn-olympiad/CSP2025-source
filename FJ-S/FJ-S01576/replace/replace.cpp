#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define R read<int>()
#define fi first
#define se second
using namespace std;
template <typename T> inline T read(){
    T x=0,fl=1; char c=getchar();
    while(c<'0'||c>'9') (c=='-'?fl=-1:1),c=getchar();
    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    return x*fl;
}
const int inf=0x3f3f3f3f,K=200005,N=5000005;
const ll INF=0x3f3f3f3f3f3f3f3f;
int n,m,L;
char s[N],t[N],str[N];
map<pair<string,string>,int> mp;
queue<int> q;
struct ACAM{
    struct node{
        node(){
            memset(ch,0,sizeof ch);
            memset(nx,0,sizeof nx);
            f=cnt=0;
        }
        int ch[27],nx[27],fa,f,cnt; char w;
    };
    vector<node> v;
    void init(){ v.resize(1),v[0].f=-1; }
    void ins(int len){
        int x=0;
        for(int i=1;i<=len;i++){
            if(!v[x].ch[str[i]-'a']){
                v[x].ch[str[i]-'a']=v.size();
                v.resize(v.size()+1);
                v.back().fa=x,v.back().w=str[i]-'a';
            }
            x=v[x].ch[str[i]-'a'];
        }
        v[x].cnt++;
    }
    void calc(){
        q.push(0);
        while(q.size()){
            int x=q.front(); q.pop();
            for(int i=0;i<27;i++){
                if(v[x].ch[i])
                    q.push(v[x].ch[i]);
            }
            if(x){
                v[x].f=v[v[x].fa].f;
                while(v[x].f>=0&&!v[v[x].f].ch[v[x].w])
                    v[x].f=v[v[x].f].f;
                if(v[x].f==-1) v[x].f=0;
                else v[x].f=v[v[x].f].ch[v[x].w];
                v[x].cnt+=v[v[x].f].cnt;
            }
            for(int i=0;i<27;i++){
                if(v[x].ch[i]||x==0) v[x].nx[i]=v[x].ch[i];
                else v[x].nx[i]=v[v[x].f].nx[i];
            }
        }
        // for(int i=0;i<v.size();i++){
        //     printf("%d %d: ",i,v[i].f);
        //     for(int j=0;j<27;j++)
        //         if(v[i].ch[j])
        //             printf("[%c %d] ",'a'+j,v[i].ch[j]);
        //     puts("");
        // }
    }
    int ask(int len){
        int x=0,ans=0;
        for(int i=1;i<=len;i++){
            x=v[x].nx[str[i]-'a'];
            ans+=v[x].cnt;
        }
        return ans;
    }
}a[K];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    n=R,m=R;
    for(int i=1;i<=n;i++){
        scanf("%s%s",s+1,t+1);
        int len=strlen(s+1),lp=0,rp;
        for(int j=1;j<=len;j++){
            if(s[j]!=t[j])
            { lp=j; break; }
        }
        if(lp==0) continue;
        for(int j=len;j;j--){
            if(s[j]!=t[j])
            { rp=j; break; }
        }
        int nl=0;
        for(int j=1;j<lp;j++) str[++nl]=s[j];
        str[++nl]='z'+1;
        for(int j=rp+1;j<=len;j++) str[++nl]=s[j];
        string p,q;
        for(int j=lp;j<=rp;j++)
            p+=s[j],q+=t[j];
        if(mp.find({p,q})==mp.end()) mp[{p,q}]=++L,a[L].init();
        str[nl+1]=0;
        // if(mp[{p,q}]==277)
        //     printf("+ %d, %d %s(%d) %s %s\n",i,mp[{p,q}],str+1,nl,p.c_str(),q.c_str());
        a[mp[{p,q}]].ins(nl);
    }
    for(int i=1;i<=L;i++) a[i].calc();
    for(int i=1;i<=m;i++){
        scanf("%s%s",s+1,t+1);
        int len=strlen(s+1),lt=strlen(t+1),lp,rp;
        if(len!=lt){ puts("0"); continue; }
        for(int j=1;j<=len;j++){
            if(s[j]!=t[j])
            { lp=j; break; }
        }
        for(int j=len;j;j--){
            if(s[j]!=t[j])
            { rp=j; break; }
        }
        int nl=0;
        for(int j=1;j<lp;j++) str[++nl]=s[j];
        str[++nl]='z'+1;
        for(int j=rp+1;j<=len;j++) str[++nl]=s[j];
        string p,q;
        for(int j=lp;j<=rp;j++)
            p+=s[j],q+=t[j];
        // str[nl+1]=0;
        // if(i==1070) printf("? %d %s %s %s\n",mp[{p,q}],str+1,p.c_str(),q.c_str()),exit(0);
        if(mp.find({p,q})==mp.end()) puts("0");
        else printf("%d\n",a[mp[{p,q}]].ask(nl));
    }
    cerr<<1.0*clock()/CLOCKS_PER_SEC<<endl;
    return 0;
}