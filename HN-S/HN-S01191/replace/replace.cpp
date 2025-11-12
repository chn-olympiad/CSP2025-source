#include<bits/stdc++.h>

const int N=2e5,BASE=179,MOD=1e9+7,LEN=5e6;

typedef long long int_64;

std::string s[2][N+5],t1,t2;
std::vector<int_64>val[2][N+5],v1,v2;

int_64 pow_base[LEN+5];

void do_hash(const std::string &s,std::vector<int_64>&v)
{
    v.clear();
    v.resize(s.size()+1,0);
    for(int i=0;i<s.size();++i)
        v[i+1]=(v[i]*BASE%MOD+s[i])%MOD;
}

void pre()
{
    pow_base[0]=1;
    for(int i=1;i<=LEN;++i)pow_base[i]=pow_base[i-1]*BASE%MOD;
}

int_64 get_val(std::vector<int_64>&v,int l,int r)
{
    if(l>r)return 0;
    return (v[r]-v[l-1]*pow_base[r-l+1]%MOD+MOD)%MOD;
}

bool check(int x)
{
    int lent=t1.size(),lens=s[0][x].size();
    for(int p=1;p+lens-1<=lent;++p)
    {
        if(get_val(v1,1,p-1)!=get_val(v2,1,p-1))break;
        if(get_val(v1,p+lens,lent)!=get_val(v2,p+lens,lent))continue;
        if(get_val(v1,p,p+lens-1)==val[0][x][lens]&&
           get_val(v2,p,p+lens-1)==val[1][x][lens])
            return true;
    }
    return false;
}

struct Opt{int x,y,tag;};
std::unordered_set<int>a;std::vector<Opt>opts[LEN*2+5];
int ans[N+5],tree[LEN+5];

int lowbit(int x){return -x&x;}
void add(int x,int v){while(x<=LEN){tree[x]+=v;x+=lowbit(x);}}
int query(int x){int res=0;while(x){res+=tree[x];x-=lowbit(x);}return res;}

signed main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);

    int n,q,L1=0;
    std::cin>>n>>q;
    for(int i=1;i<=n;++i)
    {
        std::cin>>s[0][i]>>s[1][i];
        do_hash(s[0][i],val[0][i]);
        do_hash(s[1][i],val[1][i]);
        L1+=s[0][i].size();
    }

    if(L1<=2000)
    {
        pre();
        while(q--)
        {
            std::cin>>t1>>t2;
            if(t1.size()!=t2.size()){std::cout<<"0\n";continue;}

            do_hash(t1,v1);
            do_hash(t2,v2);

            int ans=0;
            for(int i=1;i<=n;++i)ans+=check(i);
            std::cout<<ans<<'\n';
        }
    }
    else
    {
        for(int i=1,p0,p1;i<=n;++i)
        {
            for(int j=0;j<s[0][i].size();++j)
            {
                if(s[0][i][j]=='b')p0=j;
                if(s[1][i][j]=='b')p1=j;
            }
            opts[p1-p0+LEN].push_back({std::min(p0,p1),
            s[0][i].size()-std::max(p1,p0),0});
            a.insert(p1-p0+LEN);
        }
        
        for(int i=1,p0,p1;i<=q;++i)
        {
            std::cin>>t1>>t2;
            if(t1.size()!=t2.size())continue;
            for(int j=0;j<t1.size();++j)
            {
                if(t1[j]=='b')p0=j;
                if(t2[j]=='b')p1=j;
            }
            if(!a.count(p1-p0+LEN))continue;
            opts[p1-p0+LEN].push_back({std::min(p0,p1),
            t1.size()-std::max(p1,p0),i});
        }

        for(auto &i:a)
            std::sort(opts[i].begin(),opts[i].end(),[](const Opt&a,const Opt&b)
            {if(a.x!=b.x)return a.x<b.x;if(a.y!=b.y)return a.y<b.y;return a.tag<b.tag;});

        for(auto &i:a)
        {
            for(auto &j:opts[i])
            {
                if(j.tag)ans[j.tag]=query(j.y);
                else add(j.y,1);
            }
            for(auto &j:opts[i])
                if(!j.tag)add(j.y,-1);
        }

        for(int i=1;i<=q;++i)std::cout<<ans[i]<<'\n';
    }
    return 0;
}