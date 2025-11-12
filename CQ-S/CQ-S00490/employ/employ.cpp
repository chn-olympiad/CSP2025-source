#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod=998244353,inf=0x3f3f3f3f3f3f3f3f;
const int N=5e2+10,M=2e5+10;
mt19937 rnd(time(0));
int a[N],n,m,c[N];
int f[1ll<<20][20];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    cin >> n >> m;
    for ( int i = 1 ; i <= n ; i++ )
    {
        char ch;cin >> ch;
        a[i]=ch-'0';
    }
    for ( int i = 1 ; i <= n ; i++ )cin >> c[i];
    if(n==m)
    {
        for ( int i = 1 ; i <= n ; i++ )
            if(c[i]==0||a[i]==0)return cout << 0,0;
        int ans=1;
        for ( int i = 1 ; i <= n ; i++ )ans=ans*i%mod;
        return cout << ans,0;
    }
    f[(1ll<<n)-1][0]=1;
    for ( int i = (1ll<<n)-1 ; i > 0 ; i-- )
    {
        int m=n-__builtin_popcount(i);
        for ( int j = 0 ; j <= n ; j++ )
        {
            f[i][j]%=mod;
            for ( int k = 1 ; k <= n ; k++ )
            {
                if(!((i>>k-1)&1))continue;
                f[i^(1ll<<k-1)][j+(a[m+1]==0||j>=c[k])]+=f[i][j];
            }
        }
    }
    int ans=0;
    for ( int i = 0 ; i <= n-m ; i++ )ans+=f[0][i]%mod;
    cout << ans%mod << endl;
	return 0;
 } 
/*
1~5 状压
m=n 没有 0 就是 n!，否则 0
24pts

A 全排列
没那么简单，描述是在他“之前”，也就是这个和正解应该没什么差别？
一个计数想法是 f[x][y] 表示第 x 天过去了录取了 y 个人。缺点是不知道哪些人还没面。
对于排列计数的另一个想法是 f[x] 表示已经弄完了前 x 个人。但是显然没什么前途。

对于 A 性质，有一些人是关键的。也就是 c=0 的人，无论如何都会跑路。
每个人都可以看成一个函数 f(x)=x<c?x:x+1
初始为 0，最后要让值 <=n-m。非 A 性质的情况就是某几层的 f 被替换为 f(x)=x+1
（我们需要用到的只有目前有几个 c 会让 f 变大或者不变。）
那么一定要记的就只有到了第几层，目前的值，用了几个能使目前的 f 不变的。
并且由于复杂度要求 n^3，一定只能记这些。
f[x][y][z] 表示到了第 x 层，目前值为 y，而之前用了 y<c 的用了 z 个。
那么问题就是转移了。难点仍然在于你不知道 y 提升后你还有几个能让 y 不变的。
我们给他做成一个网格，然后每次选一个就是向右，可能会向上一格，每条路径有一个权（能走出这条路径的方案数）
求向上次数 <=n-m 的所有路径的权值和。

算了继续想暴力
B 枚举 s=1 的位置哪些能入聘，得到每个位置的限制形如 x<=v/x>=v
然后在 n 个里排出这些的方案数 *(n-p)!，p 为 s=1 位置的数量。
现在问题来了，如何解决这个计数?
我怀疑这个性质也是一个切入口。

已严肃决定先去写 T3
*/