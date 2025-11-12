#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
ll ans;
int t,n,a,b,c;
int dt[N][4],ca[N],cb[N],cc[N];
bool cmpa(int x,int y)
{
    return dt[x][1]-max(dt[x][2],dt[x][3])<dt[y][1]-max(dt[y][2],dt[y][3]);
}
bool cmpb(int x,int y)
{
    return dt[x][2]-max(dt[x][1],dt[x][3])<dt[y][2]-max(dt[y][1],dt[y][3]);
}
bool cmpc(int x,int y)
{
    return dt[x][3]-max(dt[x][1],dt[x][2])<dt[y][3]-max(dt[y][1],dt[y][2]);
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        ans=0;
        a=b=c=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d",&dt[i][1],&dt[i][2],&dt[i][3]);
            if(max(dt[i][1],max(dt[i][2],dt[i][3]))==dt[i][1]) ca[++a]=i;
            else if(max(dt[i][1],max(dt[i][2],dt[i][3]))==dt[i][2]) cb[++b]=i;
            else cc[++c]=i;
            ans+=max(dt[i][1],max(dt[i][2],dt[i][3]));
        }
        if(a>n/2)
        {
            sort(ca+1,ca+a+1,cmpa);
            for(int i=1;i<=a-n/2;i++) ans-=dt[ca[i]][1]-max(dt[ca[i]][2],dt[ca[i]][3]);
        }
        else if(b>n/2)
        {
            sort(cb+1,cb+b+1,cmpb);
            for(int i=1;i<=b-n/2;i++) ans-=dt[cb[i]][2]-max(dt[cb[i]][1],dt[cb[i]][3]);
        }
        else if(c>n/2)
        {
            sort(cc+1,cc+c+1,cmpc);
            for(int i=1;i<=c-n/2;i++) ans-=dt[cc[i]][3]-max(dt[cc[i]][1],dt[cc[i]][2]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
