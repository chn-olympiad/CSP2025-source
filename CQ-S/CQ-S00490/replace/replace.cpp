#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int inf=0x3f3f3f3f3f3f3f3f;
// const int mod=998244353,inf=0x3f3f3f3f3f3f3f3f;
const int N=2e5+10,M=5e6+10;
mt19937 rnd(time(0));
int n,q;
vector<int>vec;
const int base1=131,base2=129;
const int mod1=998244853,mod2=1e9+9;
vector<pair<int,int>>h[N];
pair<int,int>pw[M];
struct HashTable{
    struct node{
        pair<int,int>h1,h2;
        vector<pair<int,int>>id;
        int nxt;
    }a[M];
    int head[M],tot;
    const int md=4990019;
    int hashfunc(pair<int,int>h1,pair<int,int>h2)
    {
        h1.first%=md,h1.second%=md;
        h2.first%=md,h2.second%=md;
        return h1.first*h1.second%md*h2.first%md*h2.second%md;
    }
    void insert(pair<int,int>h1,pair<int,int>h2,int id,int P)
    {
        int p=hashfunc(h1,h2);
        int flg=0;
        for ( int i = head[p] ; i ; i=a[i].nxt )
        {
            if(a[i].h1==h1&&a[i].h2==h2)
            {
                flg=1,a[i].id.push_back({id,P});
                break;
            }
        }
        if(!flg)
        {
            a[++tot]={h1,h2,{{id,P}},head[p]};
            head[p]=tot;
        }
    }
    vector<pair<int,int>>query(pair<int,int>h1,pair<int,int>h2)
    {
        int p=hashfunc(h1,h2);
        for ( int i = head[p] ; i ; i=a[i].nxt )
        {
            if(a[i].h1==h1&&a[i].h2==h2)
                return a[i].id;
        }
        return {};
    }
}H1,H2;
int vis[N];
// namespace B{
//     vector<pair<int,int>>xg[M+M+20];
//     struct Q{int l,r,id;};
//     vector<Q>cx[M+M+20];
//     int ans[N];
//     vector<int>b;
//     int t[M+M+20];
//     int lowbit(int x){return x&(-x);}
//     int m;
//     void upd(int x,int v)
//     {
//         for ( int i = x ; i <= m ; i+=lowbit(i) )
//             t[i]+=v;
//     }
//     int calc(int x,int ans=0)
//     {
//         for ( int i = x ; i ; i-=lowbit(i) )ans+=t[i];
//         return ans;
//     }
//     void query(int detp)
//     {
//         for ( auto x:xg[detp+M] )
//             b.push_back(x.first),
//             b.push_back(x.second);
//         for ( auto x:cx[detp+M] )
//             b.push_back(x.l),b.push_back(x.r);
//         sort(b.begin(),b.end());
//         b.erase(unique(b.begin(),b.end()),b.end());
//         //
//     }
//     void solveB()
//     {
//         for ( int i = 1 ; i <= n ; i++ )
//         {
//             string s0,s1;cin >> s0 >> s1;
//             int m=s0.size();
//             int p0,p1;
//             for ( int j = 0 ; j < m ; j++ )
//                 if(s0[j]=='b')p0=j;
//             for ( int j = 0 ; j < m ; j++ )
//                 if(s1[j]=='b')p1=j;
//             xg[p0-p1+M].push_back({p0+1,m-p0+1});
//         }
//         for ( int i = 1 ; i <= q ; i++ )
//         {
//             string s0,s1;cin >> s0 >> s1;
//             int m=s0.size();
//             int p0,p1;
//             for ( int j = 0 ; j < m ; j++ )
//                 if(s0[j]=='b')p0=j;
//             for ( int j = 0 ; j < m ; j++ )
//                 if(s1[j]=='b')p1=j;
//             cx[p0-p1+M].push_back({p0+1,m-p0+1,i});
//         }
//         for ( int i = -M ; i <= M ; i++ )query(i);
//     }
// }
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
    cin >> n >> q;
    // if(n*q>1e8)return solveB(),0;
    pw[0]={1,1};
    for ( int i = 1 ; i <= 5e6 ; i++ )
        pw[i]={pw[i-1].first*base1%mod1,pw[i-1].second*base2%mod2};
    // int CNT=0;
    // int cl=clock();
    for ( int i = 1 ; i <= n ; i++ )
    {
        string s0,s1;
        cin >> s0 >> s1;
        int m=s0.size();
        // CNT+=m;
        pair<int,int>h1={0,0},h2={0,0};
        for ( int j = 0 ; j < m ; j++ )
        {
            h1.first+=pw[j].first*s0[j]%mod1;
            h1.second+=pw[j].second*s0[j]%mod2;
            h2.first+=pw[j].first*s1[j]%mod1;
            h2.second+=pw[j].second*s1[j]%mod2;
            h1.first%=mod1,h2.first%=mod1;
            h1.second%=mod2,h2.second%=mod2;
            H1.insert(h1,h2,i,j+1);
        }
        h1={0,0},h2={0,0};
        for ( int j = m-1 ; j >= 0 ; j-- )
        {
            h1.first=h1.first*base1%mod1+s0[j];
            h1.second=h1.second*base2%mod2+s0[j];
            h2.first=h2.first*base1%mod1+s1[j];
            h2.second=h2.second*base2%mod2+s1[j];
            h1.first%=mod1,h2.first%=mod1;
            h1.second%=mod2,h2.second%=mod2;
            H2.insert(h1,h2,i,j+1);
        }
    }
    // cerr << clock()-cl << endl;
    // cerr << CNT << endl;
    for ( int T = 1 ; T <= q ; T++ )
    {
        string t0,t1;cin >> t0 >> t1;
        if(t0.size()!=t1.size())
        {
            cout << "0\n";
            continue;
        }
        int m=t0.size();
        int l=inf,r=0;
        for ( int i = 0 ; i < m ; i++ )
            if(t0[i]!=t1[i])l=min(l,i),r=i;
        pair<int,int>h1={0,0},h2={0,0};
        for ( int i = l ; i <= r ; i++ )
        {
            h1.first+=pw[i-l].first*t0[i]%mod1;
            h1.second+=pw[i-l].second*t0[i]%mod2;
            h2.first+=pw[i-l].first*t1[i]%mod1;
            h2.second+=pw[i-l].second*t1[i]%mod2;
        }
        h1.first%=mod1,h2.first%=mod1;
        h1.second%=mod2,h2.second%=mod2;
        vector<pair<int,int>>V;V.clear();
        auto v=H1.query(h1,h2);V=v;
        for ( auto x:v )vis[x.first]=x.second;
        for ( int i = l-1 ; i >= 0 ; i-- )
        {
            h1.first=h1.first*base1%mod1+t0[i];
            h1.second=h1.second*base2%mod2+t0[i];
            h2.first=h2.first*base1%mod1+t1[i];
            h2.second=h2.second*base2%mod2+t1[i];
            h1.first%=mod1,h2.first%=mod1;
            h1.second%=mod2,h2.second%=mod2;
            v=H1.query(h1,h2);
            for ( auto x:v )vis[x.first]=x.second,V.push_back(x);
        }
        h1={0,0},h2={0,0};
        for ( int i = l ; i <= r ; i++ )
        {
            h1.first+=pw[i-l].first*t0[i]%mod1;
            h1.second+=pw[i-l].second*t0[i]%mod2;
            h2.first+=pw[i-l].first*t1[i]%mod1;
            h2.second+=pw[i-l].second*t1[i]%mod2;
        }
        h1.first%=mod1,h2.first%=mod1;
        h1.second%=mod2,h2.second%=mod2;
        v=H2.query(h1,h2);
        int ans=0;
        for ( auto x:v )ans+=vis[x.first]-x.second+1==r-l+1;
        for ( int i = r+1 ; i < m ; i++ )
        {
            h1.first+=pw[i-l].first*t0[i]%mod1;
            h1.second+=pw[i-l].second*t0[i]%mod2;
            h2.first+=pw[i-l].first*t1[i]%mod1;
            h2.second+=pw[i-l].second*t1[i]%mod2;
            h1.first%=mod1,h2.first%=mod1;
            h1.second%=mod2,h2.second%=mod2;
            v=H2.query(h1,h2);
            for ( auto x:v )ans+=vis[x.first]-x.second+1==r-l+1;
        }
        cout << ans << endl;
        for ( auto x:V )vis[x.first]=0;
    }
	return 0;
}
/*
sub A
根号分治，长度 >sqrt(L) 的替换只有约 2000 个。
一个询问可以找到一个最短的要替换的串。枚举包含这个的长度 < B 的串，共计最多 b^2 个。然后哈希找有没有符合要求的替换。
这样复杂度为 $O(q (L/B+B^2))$，B 取 200 即可做到 $O(q*6e4)$
能过 subA 和暴力。一共 50。

如果能把 <B 的部分压到 O(B) 那就大有希望，想一下。
也许能压倒 O(L2)。找到最短要改变的区间后枚举改变的左端点。这样要做的就是找到所有前缀是一些东西的改变串。右端点同理。
问题：可能符合这种条件的串会太多。你无法对所有的这样的串 check。
那我们就要从 check 入手，发现你至少要先保证你除了想要修改的部分以外相等。
在刚刚的根号分治中我们也可以直接枚举想要修改的部分？
好不对啊。。。

欸刚刚的过程中，我们把修改放到 trie 上之后（边权有两个字符）就是要求 Atrie 上的子树与 Btrie 上的子树里有东西相等。
但是这样的查询数量很多，不会要上 sam 吧？

2048M???????
很像 bitset 但是 1s 肯定不是了

感觉可以确诊 SAM 了，直接去看 T4，没头绪就回来写暴力
当然这 50 分好像最简单暴力也可以？

对于每个大替换怎么做？
我怎么不会做？
我怎么一分都不会？
25 的纯暴力还是会的

这个 B 性质感觉很有前途啊
显然 B 性质就是一个修改可以将一个 b 偏移一定量，但是要求这个 b 距离左端点至少多少，距离右端点至少多少。
即一个询问拥有两个属性 (p1,p2,detp) 表示 b 距离左端点的长度，距离右端点的长度以及需要偏移多少。
是不是没法作？
按照 detp 分类然后离散化单独做就好了，剩下 10min 能写马
弃疗。

继续想 A 性质，直接使用之前试图压根号分治复杂度失败时的做法？(pa2)
好像对完了，复杂度 O(nq+L1+L2)。暴力也可以沿用这个做法。
实现的话应该只能手写哈希表了。

需要打一些补丁，比如强制这个前后缀有交。大样例还是太强大了。

完蛋了。

luogu uid=530468
goodbye.
*/