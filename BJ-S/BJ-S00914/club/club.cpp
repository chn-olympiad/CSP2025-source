#include <bits/stdc++.h>
#define int long long
using namespace std;
int t,n,sum[10],ans;
struct node
{
    int a,b,c;
    int fir,sec;
    int minn,maxx,midd;
    int f;
}mem[100010];
bool cmp(node a,node b)
{
    return a.f>b.f;
}
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        ans=0;
        memset(sum,0,sizeof sum);
        for(int i=1;i<=n;i++)
        {
            scanf("%lld%lld%lld",&mem[i].a,&mem[i].b,&mem[i].c);
            mem[i].minn=min(mem[i].a,min(mem[i].b,mem[i].c));
            mem[i].maxx=max(mem[i].a,max(mem[i].b,mem[i].c));
            mem[i].midd=mem[i].a+mem[i].b+mem[i].c-mem[i].minn-mem[i].maxx;
            mem[i].f=mem[i].maxx-mem[i].midd;
            if(mem[i].a==mem[i].minn)
            {
                if(mem[i].b==mem[i].midd)
                {
                    mem[i].fir=3;
                    mem[i].sec=2;
                }
                else
                {
                    mem[i].fir=2;
                    mem[i].sec=3;
                }
                continue;
            }
            if(mem[i].b==mem[i].minn)
            {
                if(mem[i].c==mem[i].midd)
                {
                    mem[i].fir=1;
                    mem[i].sec=3;
                }
                else
                {
                    mem[i].fir=3;
                    mem[i].sec=1;
                }
                continue;
            }
            if(mem[i].c==mem[i].minn)
            {
                if(mem[i].b==mem[i].midd)
                {
                    mem[i].fir=1;
                    mem[i].sec=2;
                }
                else
                {
                    mem[i].fir=2;
                    mem[i].sec=1;
                }
                continue;
            }
        }
        sort(mem+1,mem+n+1,cmp);
        for(int i=1;i<=n;i++)
        {
            if(sum[mem[i].fir]==n/2)
            {
                sum[mem[i].sec]++;
                ans+=mem[i].midd;
            }
            else
            {
                sum[mem[i].fir]++;
                ans+=mem[i].maxx;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
