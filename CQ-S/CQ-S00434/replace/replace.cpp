#include<bits/stdc++.h>
using namespace std;
namespace SOLUTION{
    constexpr int maxn=2e5+3,maxm=5e6+6,table_size=2e6+3;
    typedef long long ll;typedef unsigned long long ull;
    #define int ll
    template<int mod>inline int addition(int u,int v)
        {int tem=u+v;return tem>=mod?tem-mod:tem;}
    template<int mod0,int mod1>class hash{
        public:int val0,val1;constexpr hash():val0(0),val1(0){}
        constexpr hash(int val0,int val1):val0(val0),val1(val1){}
        constexpr hash(int val):val0(val),val1(val){}
        inline hash operator+(const hash&add)const
            {return hash(addition<mod0>(val0,add.val0),addition<mod1>(val1,add.val1));}
        inline hash operator*(const hash&mul)const
            {return hash((ll)val0*mul.val0%mod0,(ll)val1*mul.val1%mod1);}
        inline bool operator==(const hash&comp)const{return val0==comp.val0&&val1==comp.val1;}
        inline ull operator()()const{return (ull)val0<<32|val1;}
    };typedef hash<998244353,1000000007>hashvalue;constexpr hashvalue coe(67,101);
    class node{
        public:hashvalue value;int nex,count;constexpr node():nex(0),count(0){}
        constexpr node(hashvalue value,int nex):value(value),nex(nex),count(0){}
    }ver[maxn];ll ans[maxn];vector<int>ope[maxn],que[maxm>>1];
    vector<hashvalue>put[maxm>>1];
    int head[table_size],table_tot;
    inline int find(const hashvalue&ins,int pos=-1){
        int now=head[pos!=-1?pos:ins()%table_size];
        while(now){if(ver[now].value==ins)return now;now=ver[now].nex;}
        return now;
    }
    inline int insert(const hashvalue&ins){
        int pos=ins()%table_size,iter=find(ins,pos);if(iter)return iter;
        ver[++table_tot]=node(ins,head[pos]);return head[pos]=table_tot;
    }
    char tex[maxm],str[maxm];int bound[2][maxn]
    ,begin[2][maxn],end[2][maxn],son[maxm>>1][26];
    inline void solve(int u){
        for(const hashvalue&i:put[u])++ver[insert(i)].count;
        for(int i:que[u]){ans[i]=ver[find(hashvalue())].count;
            hashvalue value;for(int k=end[1][i]+1;k<bound[1][i+1]-bound[1][i]>>1;++k)
                ans[i]+=ver[find(value=value*coe+(str[bound[1][i]+k]-'a'+1))].count;}
        for(int i=0;i<26;++i)if(son[u][i])solve(son[u][i]);
        for(const hashvalue&i:put[u])--ver[find(i)].count;
    }
    inline int Main(){
        int n,q;cin>>n>>q;for(int i=1;i<=n;++i){const int&addr=bound[0][i];
            cin>>tex+addr;int m=strlen(tex+addr);cin>>tex+addr+m;
            //clog<<"m: "<<m<<"\n";
            bound[0][i+1]=addr+(m<<1),end[0][i]=m-1;while(begin[0][i]<m
                &&tex[addr+begin[0][i]]==tex[addr+m+begin[0][i]])++begin[0][i];
            if(begin[0][i]==m)continue;
            while(tex[addr+end[0][i]]==tex[addr+m+end[0][i]])--end[0][i];
            //clog<<"range: "<<begin[0][i]<<' '<<end[0][i]<<'\n';
            hashvalue value;for(int j=end[0][i];j>=begin[0][i];--j)
                value=value*coe+(tex[addr+m+j]-'a'+1);
            for(int j=end[0][i];j>=begin[0][i];--j)
                value=value*coe+(tex[addr+j]-'a'+1);
            //clog<<"insert: "<<value()<<'\n';
            ope[insert(value)].push_back(i);}
        for(int i=1;i<=q;++i){const int&addr=bound[1][i];
            cin>>str+addr;int m=strlen(str+addr);cin>>str+addr+m;
            int len=strlen(str+addr+m);bound[1][i+1]=addr+len+m;if(len!=m)continue;
            while(begin[1][i]<m&&str[addr+begin[1][i]]
                ==str[addr+m+begin[1][i]])++begin[1][i];
            end[1][i]=m-1;while(str[addr+end[1][i]]==str[addr+m+end[1][i]])--end[1][i];
            hashvalue value;for(int j=end[1][i];j>=begin[1][i];--j)
                value=value*coe+(str[addr+m+j]-'a'+1);
            for(int j=end[1][i];j>=begin[1][i];--j)
                value=value*coe+(str[addr+j]-'a'+1);
            ope[find(value)].push_back(n+i);}
        //clog<<"talbe_tot: "<<table_tot<<'\n';
        memset(head,0,sizeof(head));for(int num=table_tot,i=1;i<=num;++i){
            //for(int j:ope[i])clog<<j<<' ';clog<<'\n';
            int tree_tot=1;for(int j:ope[i])if(j>n){
                int now=1;for(int k=begin[1][j-n]-1;k>=0;--k){
                    char ch=str[bound[1][j-n]+k]-'a';
                    now=son[now][ch]?son[now][ch]:(son[now][ch]=++tree_tot);}
                que[now].push_back(j-n);}
            for(int j:ope[i])if(j<=n){
                int now=1;for(int k=begin[0][j]-1;k>=0;--k)
                    now=son[now][tex[bound[0][j]+k]-'a'];
                if(!now)continue;hashvalue value;
                for(int k=end[0][j]+1;k<bound[0][j+1]-bound
                    [0][j]>>1;++k)value=value*coe+(tex[bound[0][j]+k]-'a'+1);
                put[now].push_back(value);}
            table_tot=0,solve(1);for(int i=1;i<=tree_tot;++i){
                for(const hashvalue&j:put[i])head[j()%table_size]=0;
                put[i].clear(),que[i].clear(),memset(son[i],0,sizeof(son[i]));}
        }for(int i=1;i<=q;++i)cout<<ans[i]<<'\n';return 0;
    }
    #undef int
}
int main(){freopen("replace.in","r",stdin),freopen("replace.out","w",stdout);
    //freopen("mine.out","w",stderr);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    SOLUTION::Main();return 0;
}