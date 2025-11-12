#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
struct Node{
    int ma,l,r;
}gg[N];

int n,k,m;
int a[N],b[N],c[N],v[N];
int cnt,ans;
int cmp(Node x,Node y)
{
    return x.ma<y.ma;
}
signed main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=b[i-1]^a[i];
        int vv=0;
        if(a[i]!=1)  vv=1;
    }
    if(vv==0){
        cout<<n;
        return 0;
    }
    for(int lenn=1;lenn<=n;lenn++)
    {
        for(int i=1;i<=n;i++)
        {
            if(i+lenn-1<=n)
            {
                int j=i+lenn-1;
                int ans=b[j]^b[i-1];
                if(ans==k)
                {
                    c[i]++;
                    c[j+1]--;
                    gg[++cnt].l=i;
                    gg[cnt].r=j;
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        c[i]=c[i-1]+c[i];
    }
    for(int i=1;i<=cnt;i++)
    {
        int man=0;
        for(int j=gg[i].l;j<=gg[i].r;j++)
        {
            if(c[j]>man)  man=a[j];
        }
        gg[i].ma=man;
    }
    sort(gg+1,gg+cnt+1,cmp);
    for(int i=1;i<=cnt;i++)
    {
        int vis=0;
        for(int j=gg[i].l;j<=gg[i].r;j++)
        {
            if(v[j]!=0)
            {
                vis=1;
                break;
            }
        }
        if(vis==0)
        {
            for(int j=gg[i].l;j<=gg[i].r;j++)  v[j]=1;
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
