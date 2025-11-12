#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct A
{
    long long l,r,w;
};
A a[2000010];
long long b[10010];
int fa[2000010];
int lst=0;
int fd(int x)
{
    if(fa[x]==x)return x;
    return fa[x]=fd(fa[x]);
}
void hb(int x,int y)
{

    int t1=fd(x),t2=fd(y);
    fa[t1]=t2;
}
bool cmp(A x,A y)
{
    return x.w<y.w;
}
int n,m,k;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    int cur=0;
    for(int i=1;i<=(k)*n+m;i++)fa[i]=i;
    for(int i=1;i<=m;i++)
    {
        cur++;
        cin>>a[cur].l>>a[cur].r>>a[cur].w;
    }
    for(int i=1;i<=k;i++)
    {
        long long x;
        cin>>x;
        int id=1;

        for(int j=1;j<=n;j++)
        {
            cin>>b[j];
            cur++;
            a[cur].l=i+n;
            a[cur].r=j;
            a[cur].w=b[j];
        }
    }
    sort(a+1,a+cur+1,cmp);
    //int lt=0;
    //for(int i=1;i<=n;i++)lt=max(lt,)
    //dfs(1,0);
    long long ans=0,cnt=0;
    for(int i=1;i<=cur;i++)
    {

        if(fd(a[i].l)==fd(a[i].r))continue;
        cnt++;
        hb(a[i].l,a[i].r);
        ans+=a[i].w;
    }
    //long long ans=0;
    //for(int i=1;i<=n;i++)ans=max(ans,last[i]);
    cout<<ans<<endl;

}
