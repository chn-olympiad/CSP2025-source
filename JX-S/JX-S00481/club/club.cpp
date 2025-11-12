#include<bits/stdc++.h>
using namespace std;
/*

*/
struct FSI{
    template<typename T>
    FSI& operator >> (T &res){
        res=0;T f=1;char ch=getchar();
        while (!isdigit(ch)){if (ch=='-') f=-1;ch=getchar();}
        while (isdigit(ch)){res=res*10+ch-'0';ch=getchar();}
        res*=f;
        return *this;
    }
}scan;
const int N=2e5+10;
typedef long long ll;
typedef pair<ll,int> pii;
int T,n,i,j,x[N],y[N],z[N],id;
ll a[N][5],ans,val;
priority_queue<pii,vector<pii>,greater<pii> > q[5];
pii tp;
void work()
{
    scan>>n;
    for (i=1;i<=n;i++) scan>>a[i][1]>>a[i][2]>>a[i][3];
    for (i=1;i<=3;i++)
    {
        while (!q[i].empty()) q[i].pop();
    }
    ans=0;
    for (i=1;i<=n;i++)
    {
        x[i]=y[i]=z[i]=0;
        for (j=1;j<=3;j++)
        {
            if (a[i][j]>=a[i][x[i]]) z[i]=y[i],y[i]=x[i],x[i]=j;
            else if (a[i][j]>=a[i][y[i]]) z[i]=y[i],y[i]=j;
            else if (a[i][j]>=a[i][z[i]]) z[i]=j;
        }
        ans+=a[i][x[i]];
        q[x[i]].push({a[i][x[i]]-a[i][y[i]],i});
        if (q[x[i]].size()>n/2)
        {
            tp=q[x[i]].top();
            q[x[i]].pop();
            val=tp.first;
            id=tp.second;
            ans-=val;
            q[y[i]].push({a[y[id]]-a[z[id]],id});
        }
        if (q[y[i]].size()>n/2)
        {
            tp=q[y[i]].top();
            q[y[i]].pop();
            val=tp.first;
            id=tp.second;
            ans-=val;
            q[z[i]].push({0,id});
        }
    }
    printf("%lld\n",ans);
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scan>>T;
    while (T--) work();
    return 0;
}