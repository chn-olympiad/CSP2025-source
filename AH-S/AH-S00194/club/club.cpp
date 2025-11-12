#include<bits/stdc++.h>
#define ll long long
#define N 100005
#define pii pair<int,int>
#define swap(a,b) (a^=b^=a^=b)
#define sqrt(a) __builtin_sqrt(a)
using namespace std;
void read(int &x)
{
    x=0;
    int f=1;
    char ch=getchar_unlocked();
    while(ch<48||ch>57)
    {
        if(ch=='-')
            f=-1;
        ch=getchar_unlocked();
    }
    while(ch>=48&&ch<=57)
        x=x*10+(ch-'0'),ch=getchar_unlocked();
    x*=f;
}
struct Node{
    int a,b,c,ma,mb,mc,ba,bb,bc;
}a[N];
int n,bm,am,cm,ans;
bool cmp(Node a,Node b)
{
    if(a.ma==b.ma)
    {
        if(a.mb==b.mb)
            return a.mc>b.mc;
        return a.mb>b.mb;
    }
    return a.ma>b.ma;
}
void dfs(int da,int b,int c,int now,int step)
{
    if(step==n+1)
    {
        ans=max(ans,now);
        return;
    }
    if(!da)
    {
        dfs(0,b-1,c,now+a[step].b,step+1);
        dfs(0,b,c-1,now+a[step].c,step+1);
    }
    if(!b)
    {
        dfs(da-1,0,c,now+a[step].a,step+1);
        dfs(da,0,c-1,now+a[step].c,step+1);
    }
    if(!c)
    {
        dfs(da,b-1,0,now+a[step].b,step+1);
        dfs(da-1,b,0,now+a[step].a,step+1);
    }
    if(a&&b&&c)
    {
		dfs(da,b-1,c,now+a[step].b,step+1);
		dfs(da-1,b,c,now+a[step].a,step+1);
		dfs(da,b,c-1,now+a[step].c,step+1);
	}
    return;
}
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T,cnt;
    read(T);
    while(T--)
    {
        ans=0;
        read(n);
        if(n==2)
        {
            for(int i=1;i<=n;i++)
                read(a[i].a),read(a[i].b),read(a[i].c),a[i].ma=max(a[i].a,max(a[i].b,a[i].c)),a[i].mc=min(a[i].a,min(a[i].b,a[i].c)),a[i].mb=a[i].a+a[i].b+a[i].c-a[i].ma-a[i].mc,a[i].ba=((a[i].ma==a[i].a)?1:((a[i].ma==a[i].b)?2:3)),a[i].bb=((a[i].mb==a[i].a)?1:((a[i].mb==a[i].b)?2:3)),a[i].bc=((a[i].mc==a[i].a)?1:((a[i].mc==a[i].b)?2:3));
            ans=max(a[1].ma+a[2].mb,a[1].mb+a[2].ma);
            printf("%d\n",ans);
            continue;
        }
        if(n<30)
        {
            for(int i=1;i<=n;i++)
                read(a[i].a),read(a[i].b),read(a[i].c);
            cnt=n/2;
            dfs(cnt,cnt,cnt,0,1);
            printf("%d\n",ans);
            continue;
        }
        for(int i=1;i<=n;i++)
            read(a[i].a),read(a[i].b),read(a[i].c),a[i].ma=max(a[i].a,max(a[i].b,a[i].c)),a[i].mc=min(a[i].a,min(a[i].b,a[i].c)),a[i].mb=a[i].a+a[i].b+a[i].c-a[i].ma-a[i].mc,a[i].ba=((a[i].ma==a[i].a)?1:((a[i].ma==a[i].b)?2:3)),a[i].bb=((a[i].mb==a[i].a)?1:((a[i].mb==a[i].b)?2:3)),a[i].bc=((a[i].mc==a[i].a)?1:((a[i].mc==a[i].b)?2:3));
        sort(a+1,a+1+n,cmp);
        am=bm=cm=0,cnt=n>>1;
        for(int i=1;i<=n;i++)
        {
            if(a[i].ba==1)
            {
                if(am!=cnt)
                    ans+=a[i].ma,am++;
                else
                {
                    ans+=a[i].mb;
                    a[i].bb==2?bm++:cm++;
                }
            }
            else if(a[i].ba==2)
            {
                if(bm!=cnt)
                    ans+=a[i].ma,bm++;
                else
                {
                    ans+=a[i].mb;
                    a[i].bb==1?am++:cm++;
                }
            }
            else
            {
                if(cm!=cnt)
                    ans+=a[i].ma,cm++;
                else
                {
                    ans+=a[i].mb;
                    a[i].bb==2?bm++:am++;
                }
            }
        }
        printf("%d\n",ans);
	}
    return 0;
}
