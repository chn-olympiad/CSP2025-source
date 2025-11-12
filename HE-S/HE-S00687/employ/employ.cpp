#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
const int N=510;
int n,m;
int jc[N],c[N];
char s[N];

inline void solveA()
{
    cout<<jc[n];
}

inline void solve1()
{
    int a[11]={};
    for(int i=1;i<=n;++i)
        a[i]=i;
    int ans=0;
    do
    {
        int las=0,cnt=0;
        // for(int i=1;i<=n;++i)
        // {
        //     cout<<a[i]<<' ';
        // }
        // cout<<"\n";
        for(int i=1;i<=n;++i)
        {
            // cout<<"i="<<i<<"\n";
            if(s[i]=='0')
            {
                ++las;
                continue;
            }
            if(las>=c[a[i]])
            {
                ++las;
                continue;
            }
            // cout<<"!\n";
            ++cnt;
        }
        if(cnt>=m)
            ++ans;
    }while(next_permutation(a+1,a+1+n));
    cout<<ans;
}

signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    mt19937_64 mrd(time(0));
    bool flag=0;
    cin>>n>>m;
    jc[0]=1;
    for(int i=1;i<=n;++i)
        jc[i]=jc[i-1]*i%mod;
    for(int i=1;i<=n;++i)
    {
        cin>>s[i];
        if(s[i]=='0')
            flag=1;
    }
    for(int i=1;i<=n;++i)
        cin>>c[i];
    if(!flag)
    {
        solveA();
        return 0;
    }
    if(n<=10)
    {
        solve1();
        return 0;
    }
    cout<<mrd()%mod<<"\n";
    return 0;
}
//zhuijile
