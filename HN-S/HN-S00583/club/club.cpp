#include<bits/stdc++.h>
#define mm 100010
#define int long long
using namespace std;
int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0' || ch>'9')
    {
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9')
    {
        x=(x<<3)+(x<<1)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
struct node
{
    int a,b,c;
}a[mm];
int n;
vector<int> a1,a2,a3;
int c[mm],tot;
int b[4];
void PUSH(vector<int> p)
{
    for(auto u:p)
    {
        b[1]=a[u].a,b[2]=a[u].b,b[3]=a[u].c;
        sort(b+1,b+3+1);
        c[++tot]=b[2]-b[3];
    }
}
void work()
{
    n=read();
    for(int i=1;i<=n;i++) a[i].a=read(),a[i].b=read(),a[i].c=read();
    a1.clear(),a2.clear(),a3.clear(),tot=0;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int maxn=max(a[i].a,max(a[i].b,a[i].c));
        ans+=maxn;
        if(a[i].a==maxn) a1.push_back(i);
        else if(a[i].b==maxn) a2.push_back(i);
        else a3.push_back(i);
    }
    if(a1.size()<=n/2 && a2.size()<=n/2 && a3.size()<=n/2) 
    {
        printf("%lld\n",ans);
        return ;
    }
    if(a1.size()>n/2) PUSH(a1);
    else if(a2.size()>n/2) PUSH(a2);
    else PUSH(a3);
    sort(c+1,c+tot+1);
    for(int i=tot;i>n/2;i--) ans+=c[i];
    printf("%lld\n",ans);
}
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T=read();
    while(T--) work();
}
/*
1
4
0 1 0
0 1 0
0 2 0
0 2 0
*/