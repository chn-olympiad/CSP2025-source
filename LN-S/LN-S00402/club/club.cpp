#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,cat,cbt,cct,t;
ll ans = 0;
struct node{ll a,b,c;}a[100010],b[100010],c[100010];
bool cmpa(node a,node b){return max(a.b,a.c)<max(b.b,b.c);}
bool cmpb(node a,node b){return max(a.a,a.c)<max(b.a,b.c);}
bool cmpc(node a,node b){return max(a.a,a.b)<max(b.a,b.b);}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        cat = cbt = cct = ans = 0;
        scanf("%d",&n);
        for(int i = 1;i<=n;i++)
        {
            ll x,y,z;
            scanf("%lld%lld%lld",&x,&y,&z);
            if(x>=y&&x>=z)a[++cat] = {x,y - x,z - x};
            else if(y>=x&&y>=z)b[++cbt] = {x - y,y,z - y};
            else if(z>=x&&z>=y)c[++cct] = {x - z,y - z,z};
        }
        sort(a+1,a+1+cat,cmpa);
        sort(b+1,b+1+cbt,cmpb);
        sort(c+1,c+1+cct,cmpc);
        for(int i = 1;i<=cat;i++)ans+=a[i].a;
        if(cat>n/2)for(int i = n/2+1;i<=cat;i++)ans+=max(a[i].b,a[i].c);
        for(int i = 1;i<=cbt;i++)ans+=b[i].b;
        if(cbt>n/2)for(int i = n/2+1;i<=cbt;i++)ans+=max(b[i].a,b[i].c);
        for(int i = 1;i<=cct;i++)ans+=c[i].c;
        if(cct>n/2)for(int i = n/2+1;i<=cct;i++)ans+=max(c[i].b,c[i].a);
        printf("%lld\n",ans);
    }
    return 0;
} 