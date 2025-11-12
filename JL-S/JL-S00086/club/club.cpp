#include<bits/stdc++.h>
using namespace std;
int k[5][100001],w[1000001];
struct x{
    int id;
    int a;
}r[100001];
struct y{
    int id;
    int b;
}s[100001];
struct z{
    int id;
    int c;
}t[100001];
bool cmp1(x p,x q)
{
    return p.a>q.a;
}
bool cmp2(y p,y q)
{
    return p.b>q.b;
}
bool cmp3(z p,z q)
{
    return p.c>q.c;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int o;
    scanf("%d",&o);
    while(o--)
    {
        int n;
        scanf("%d",&n);
        int l[3][10];
        if(n == 2)
        {
            int u,v,m,u1,v1,m1;
            scanf("%d%d%d",&u,&v,&m);
            scanf("%d%d%d",&u1,&v1,&m1);
            cout<<max({u+v1,u+m1,v+u1,v+m1,m+u1,m+v1});
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            w[i] = 0;
            k[1][i] = 0;
            k[2][i] = 0;
            k[3][i] = 0;
            r[i].a = 0;
            s[i].b = 0;
            t[i].c = 0;
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d",&r[i].a,&s[i].b,&t[i].c);
            r[i].id = i;
            s[i].id = i;
            t[i].id = i;
        }
        sort(r+1,r+1+n,cmp1);
        sort(s+1,s+1+n,cmp2);
        sort(t+1,t+1+n,cmp3);
        for(int i=1;i<=n/2;i++)
        {
            k[1][r[i].id] = r[i].a;
            k[2][s[i].id] = s[i].b;
            k[3][t[i].id] = t[i].c;
        }
        for(int i=1;i<=n;i++)
        {
            w[i] = max(k[1][i],max(k[2][i],k[3][i]));
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            ans+=w[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}
