#include<bits/stdc++.h>
#define mod 998244353
#define INF 1000000000
using namespace std;
const int maxn=505;
int n,m,ans;
int s[maxn];
int c[maxn];
int a[maxn];
int read()
{
    int u=0,v=1;
    char ch=getchar();
    while(ch<'0' || ch>'9')
    {
        if(ch=='-') v=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9')
    {
        u=(u<<3)+(u<<1)+(ch^48);
        ch=getchar();
    }
    return u*v;
}
void print(int x)
{
    if(x<0) x=-x,putchar('-');
    if(x<10) putchar(x+48);
    else print(x/10),putchar(x%10+48);
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    n=read(),m=read();
    for(int i=1;i<=n;i++)
    {
        char ch;
        ch=getchar();
        s[i]=ch-'0';
        //cout<<s[i]<<"\n";
    }
    for(int i=1;i<=n;i++)
        c[i]=read();
    for(int i=1;i<=n;i++)
        a[i]=i;
    //cout<<"\n";
    do
    {
        int u=0,cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(u>=c[a[i]]) u++;
            else
            {
                if(s[i]==0) u++;
                else cnt++;
            }
        }
        //for(int i=1;i<=n;i++)
        //    cout<<a[i]<<" ";
        //cout<<"\n"<<u<<"\n";
        if(cnt>=m) ans++;
        if(ans>=mod) ans-=mod;
    }while(next_permutation(a+1,a+n+1));
    cout<<ans;
    return 0;
}
