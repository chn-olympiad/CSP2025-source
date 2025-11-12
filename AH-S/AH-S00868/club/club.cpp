#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,sum,ans;
struct node
{
    int x,y,z;
}a[100005];
inline bool cmp(node p,node q)
{
    return max(p.y,p.z)-p.x>max(q.y,q.z)-q.x;
}
inline void change()
{
    sum=0;
    for(int i=1;i<=n;++i)
    {
        swap(a[i].x,a[i].y);
        swap(a[i].y,a[i].z);
        sum+=a[i].x;
    }
    return;
}
inline void work()
{
    sort(a+1,a+1+n,cmp);
    int cnt1=n,cnt2=0,cnt3=0;
    for(int i=1;i*2<=n;++i)
    {
        if(a[i].y>=a[i].z)
        {
            sum=sum+a[i].y-a[i].x;
            --cnt1;
            ++cnt2;
        }
        else
        {
            sum=sum+a[i].z-a[i].x;
            --cnt1;
            ++cnt3;
        }
    }
    ans=max(ans,sum);
    for(int i=n/2+1;i<=n;++i)
    {
        if(a[i].y>=a[i].z)
        {
            if(a[i].y-a[i].x<=0) break;
            if(cnt2==n/2) continue;
            sum=sum+a[i].y-a[i].x;
            ++cnt2;
            --cnt1;
        }
        else
        {
            if(a[i].z-a[i].x<=0) break;
            if(cnt3==n/2) continue;
            sum=sum+a[i].z-a[i].x;
            ++cnt3;
            --cnt1;
        }
        ans=max(ans,sum);
    }
    return;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
        {
            scanf("%d %d %d",&a[i].x,&a[i].y,&a[i].z);
        }
        for(int i=1;i<=3;++i)
        {
            change();
            work();
        }
        printf("%d\n",ans);
    }
    return 0;
}
