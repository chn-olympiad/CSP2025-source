#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+50;
struct node
{
    int fiid,finum,senum;
    bool operator < (const node &T) const
    {
        return finum-senum<T.finum-T.senum;
    }
};
int a[MAXN][4],cnt[4];
node b[4][MAXN];
node getnode(int i)
{
    node res;
    int x=a[i][1],y=a[i][2],z=a[i][3];
    if(x>=y&&y>=z)
        res={1,x,y};
    else if(x>=z&&z>=y)
        res={1,x,z};
    else if(y>=x&&x>=z)
        res={2,y,x};
    else if(y>=z&&z>=x)
        res={2,y,z};
    else if(z>=x&&x>=y)
        res={3,z,x};
    else
        res={3,z,y};
    return res;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T,n,ans;
    cin>>T;
    while(T--)
    {
        memset(cnt,0,sizeof(cnt));
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            node t=getnode(i);
            b[t.fiid][++cnt[t.fiid]]=t;
        }
        for(int i=1;i<=3;i++)
        {
            if(cnt[i]>n/2)
            {
                sort(b[i]+1,b[i]+cnt[i]+1);
                for(int j=1;j<=cnt[i]-n/2;j++)
                    ans+=b[i][j].senum;
                for(int j=cnt[i]-n/2+1;j<=cnt[i];j++)
                    ans+=b[i][j].finum;
            }
            else
                for(int j=1;j<=cnt[i];j++)
                    ans+=b[i][j].finum;
        }
        cout<<ans<<endl;
    }
    return 0;
}
