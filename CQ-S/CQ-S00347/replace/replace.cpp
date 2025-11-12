//17:59 I don't know hou much I'll get maybe 60~100
#include<bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define fi first
#define se second
using ll=long long;
using ull=unsigned long long;
const int N=2e5+5,S=5e6+5,C=26;
const ull B=131;
bool mst,f;
struct AC_auto{
    int rt,siz;
    struct node{int son[C],fail;unordered_map<ull,int>cnt;}t[S];
    vector<int>ft[S];
#define son(x,y) t[x].son[y]
    inline int new_node(){return ++siz;}
    void insert(string s,ull val){
        int p=rt;
        for(int i=0;i<s.length();i++){
            int to=s[i]-'a';
            if(!son(p,to))  son(p,to)=new_node();
            p=son(p,to);
        }
        t[p].cnt[val]++;
    }
    //t[p].son[i].fail=t[p].fail.son[i]
    //t[p].son[i]=t[p].fail.son[i]
    queue<int>q;
    void get_fail(){
        for(int i=0;i<26;i++){
            if(son(0,i))   q.push(son(0,i)),t[son(0,i)].fail=0,ft[0].push_back(son(0,i));
        }
        while(!q.empty()){
            int now=q.front();q.pop();
            for(int i=0;i<26;i++){
                if(son(now,i))  t[son(now,i)].fail=son(t[now].fail,i),q.push(son(now,i)),ft[t[son(now,i)].fail].push_back(son(now,i));
                else    son(now,i)=son(t[now].fail,i);
            }
        }
    }
    void push_down(int now){
        for(auto it:ft[now]){
            for(auto v:t[now].cnt)  t[it].cnt[v.fi]+=v.se;
            push_down(it);
        }
    }
    int query(string S,string T,int mi,bool op){
        int p=rt,ans=0;ull p1=0,p2=0;
        for(int i=0;i<S.length();i++){
            int to=S[i]-'a';
            p=son(p,to);
            p1=p1*B+S[i];p2=p2*B+T[i];
            // cerr<<i<<" "<<p1-p2<<"\n";
            if(i>=mi){
                if(op)  ans+=t[p].cnt[p1-p2];
                else{
                    int tmp=p;
                    while(tmp){
                        if(t[tmp].cnt.count(p1-p2))    ans+=t[tmp].cnt[p1-p2];
                        tmp=t[tmp].fail;
                    }
                }  
            } 
        }
        return ans;
    }
}AC;
int n,m;
string s,t;
bool ed;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cerr<<fixed<<setprecision(6)<<(&ed-&mst)/1024.0/1024.0<<"MB\n";
    double st=clock();
    cin>>n>>m;f=1;
    for(int i=1;i<=n;i++){
        cin>>s>>t;
        ull p1=0,p2=0;
        for(int j=0;j<s.length();j++)   p1=p1*B+s[j],p2=p2*B+t[j],f&=(s[j]<='b');
        AC.insert(s,p1-p2);
        // cerr<<p1-p2<<"\n";
    }
    cerr<<f<<"\n";
    AC.get_fail();
    if(f)   AC.push_down(AC.rt);
    for(int i=1;i<=m;i++){
        // cerr<<i<<"\n";
        cin>>s>>t;
        int mi=s.length()-1;
        while(s[mi]==t[mi]) mi--;
        cout<<AC.query(s,t,mi,f)<<"\n";
    }
    cerr<<fixed<<setprecision(6)<<(clock()-st)/CLOCKS_PER_SEC<<"s\n";
    bool red;
    cerr<<fixed<<setprecision(6)<<(&red-&mst)/1024.0/1024.0<<"MB\n";
}