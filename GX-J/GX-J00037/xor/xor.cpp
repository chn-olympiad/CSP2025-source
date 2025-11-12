//if ai > k and can't be xiao_diao in [l,r]: [l,r] false
//should bao_li and dui_pai
//no qian_zhui_he
//n2:pre deal for SGT(yi_huo_he),solve for for(len){for(l){[l,r]}}
//remember to vis
#include <iostream>
#define ls(p) p<<1
#define rs(p) p<<1|1
#define lowbit(x) x&(-x)
using namespace std;
typedef long long ll;
const int N = 5e5+5;

int n,k,a[N],t[N<<2];
bool vis[N<<2];
ll ans;

int read()
{
    char c = getchar();
    int ch = 0;
    while(c<'0'||c>'9')
    {
        c = getchar();
    }
    while(c>='0'&&c<='9')
    {
        ch = (ch<<3)+(ch<<1)+c-'0';
        c = getchar();
    }
    return ch;
}

void build(int p,int pl,int pr)
{
    if(pl==pr)
    {
        t[p] = a[pl];
        return;
    }
    int mid = (pl+pr)>>1;
    build(ls(p),pl,mid);
    build(rs(p),mid+1,pr);
    t[p] = t[ls(p)]^t[rs(p)];
}

void update(int p,int pl,int pr,int l,int r)
{
    if(l<=pl&&pr<=r)
    {
        vis[p] = 1;
        return;
    }
    int mid = (pl+pr)>>1;
    if(l<=mid) update(ls(p),pl,mid,l,r);
    if(r>mid) update(rs(p),mid+1,pr,l,r);
    vis[p] = vis[ls(p)]|vis[rs(p)];
}

int query(int p,int pl,int pr,int l,int r)
{
    if(l<=pl&&pr<=r) return t[p];
    int mid = (pl+pr)>>1,res = 0;
    if(l<=mid) res ^= query(ls(p),pl,mid,l,r);
    if(r>mid) res ^= query(rs(p),mid+1,pr,l,r);
    return res;
}

bool query2(int p,int pl,int pr,int l,int r)
{
    if(l<=pl&&pr<=r) return vis[p];
    int mid = (pl+pr)>>1;
    bool res = 0;
    if(l<=mid) res |= query2(ls(p),pl,mid,l,r);
    if(r>mid) res |= query2(rs(p),mid+1,pr,l,r);
    return res;
}

int main()
{
    //xor6 is 2e5
    //xor4-6: 63 69 12701
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    n = read(),k = read();
    for(int i=1;i<=n;i++) a[i] = read();
    build(1,1,n);
    for(int len=1;len<=n;len++)
    {
        for(int l=1;l+len-1<=n;l++)
        {
            int r = l+len-1;
            if(query2(1,1,n,l,r)) continue;
            if(query(1,1,n,l,r)==k)
            {
                ++ans;
                update(1,1,n,l,r);
            }
        }
    }
    printf("%lld",ans);
    return 0;
}
/*
5 8
2 7 9 8 0
*/
