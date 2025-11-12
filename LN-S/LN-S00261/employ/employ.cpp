#include<bits/stdc++.h>
#define int long long
#define inf 1e18
#define mod 998244353
using namespace std;
inline int read()
{
    char ch=getchar();
    int w=0,c=1;
    while(ch>'9'||ch<'0')
    {
        if(ch=='-')c=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        w=(w<<1)+(w<<3)+ch-48;
        ch=getchar();
    }
    return w*c;
}
#define maxn 222222
signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n=read(),m=read();
    int cnt=1;
    for(int i=1;i<=n;i++)cnt*=i,cnt%=mod;
    cout<<cnt;
    return 0;
}
