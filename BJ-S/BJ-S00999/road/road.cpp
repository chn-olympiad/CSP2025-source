#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pow power
using namespace std;
template<typename T>void read(T &x)
{
    x=0;
    int fl=1;
    char ch=getchar();
    for(;!isdigit(ch);ch=getchar()) if(ch=='-') fl=-1;
    for(;isdigit(ch);ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
    x*=fl;
}
template<typename T>void write(T x)
{
    if(x<0)
    {
        putchar('-');
        x=-x;
    }
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
template<typename T>void writesp(T x){write(x);putchar(' ');}
template<typename T>void writeln(T x){write(x);putchar('\n');}
const int N=1e5+5,M=1e6+5;
int n,m,k;
int fa[N];
int getfa(int x)
{
    if(x==fa[x]) return x;
    return fa[x]=getfa(fa[x]);
}
int merge(int x,int y)
{
    // cout<<"trem"<<x<<" "<<y<<endl;
    x=getfa(x);y=getfa(y);
    if(x==y) return 0;
    fa[x]=y;
    return 1;
}
pair<int,pair<int,int> > e[M],a[15][N],nw[N];
int len;
int w[N];
ll ans=LONG_LONG_MAX;
int pr[15];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    read(n);read(m);read(k);
    for(int i=1;i<=m;i++)
    {
        int u,v,c;
        read(u);read(v);read(c);
        e[i]=make_pair(c,make_pair(u,v));
    }
    sort(e+1,e+m+1);
    for(int i=1;i<=k;i++)
    {
        read(w[i]);
        for(int j=1;j<=n;j++)
        {
            int c;
            read(c);
            a[i][j]=make_pair(c,make_pair(n+i,j));
        }
        sort(a[i]+1,a[i]+n+1);
    }
    // cout<<"part1"<<endl;
    ll res=0;
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++) 
    {
        int u=e[i].second.first,v=e[i].second.second;
        if(merge(u,v))
        {
            nw[++len]=e[i];
            res+=e[i].first;
        }
    }
    ans=min(ans,res);
    // cout<<res<<" "<<len<<endl;
    // return 0;
    for(int s=1;s<(1<<k);s++)
    {
        for(int i=1;i<=k;i++) pr[i]=1;
        res=0;
        for(int i=1;i<=k;i++)
            if((s>>i-1)&1)
                res+=w[i];
        for(int i=1;i<=n;i++) fa[i]=i;
        int es=0,point=1;
        while(es!=n-1)
        {
            int pos=0,valr=nw[point].first;
            for(int i=1;i<=k;i++)
                if(((s>>i-1)&1))
                    if(valr>a[i][pr[i]].first) pos=i,valr=a[i][pr[i]].first;
            int u,v;
            if(pos==0) 
            {
                u=nw[point].second.first;
                v=nw[point].second.second;
                point++;
                if(merge(u,v)) es++,res+=valr;
            }
            else
            {
                int u=a[pos][pr[pos]].second.first,v=a[pos][pr[pos]].second.second;
                if(pr[pos]==1) fa[n+pos]=v,res+=valr;
                else if(merge(u,v)) es++,res+=valr;
                pr[pos]++;
            }
            // cout<<pos<<" "<<es<<endl;
            if(res>ans) break;
        }
        // cout<<"_______"<<s<<" "<<res<<endl;
        ans=min(ans,res);
    }
    writeln(ans);
    return 0;
}
// g++ cur.cpp -o cur -std=c++14 -O2 -static -Wall -Wextra 