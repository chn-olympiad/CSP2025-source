#include<cstdio>
#include<algorithm>
#include<cstring>
typedef long long ll;
ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<48||ch>57){if(ch=='-')f=-1;ch=getchar();}
    while(48<=ch&&ch<=57){x=(x*10)+(ch^48);ch=getchar();}
    return x*f;
}

inline ll max(ll x,ll y){return (x>y)?x:y;}

inline ll min(ll x,ll y){return (x<y)?x:y;}

const int N=1e5+10;

int n;

ll A[N][5];

struct node{
    ll val[5],pos,id;
}C[N];

ll maxcnt=0;

ll cnt[10];

bool cmp(node a,node b)
{
    if(a.pos==maxcnt&&b.pos!=maxcnt)
        return true;

    if(a.pos!=maxcnt&&b.pos==maxcnt)
        return false;

    ll m1=0,m2=0;

    for(int j=1;j<=3;j++)
    {
        if(j!=maxcnt)
            m1=max(a.val[j],m1);
    }

    for(int j=1;j<=3;j++)
    {
        if(j!=maxcnt)
            m2=max(b.val[j],m2);
    }

    return a.val[maxcnt]-m1<b.val[maxcnt]-m2;
}

void solve()
{
    n=read();

    cnt[1]=cnt[2]=cnt[3]=maxcnt=0;

    ll ans=0;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=3;j++)
            A[i][j]=read();

    for(int i=1;i<=n;i++)
    {
        ll maxm=-1,pos=0;

        for(int j=1;j<=3;j++)
        {
            if(A[i][j]>maxm)
                maxm=A[i][j],pos=j;

            C[i].val[j]=A[i][j];
        }

        cnt[pos]++,ans+=maxm;

        C[i].pos=pos,C[i].id=i;
    }

    ll maxm=-1;

    for(int j=1;j<=3;j++)
        if(cnt[j]>maxm)
            maxm=cnt[j],maxcnt=j;

    if(cnt[maxcnt]<=(n/2))
    {
        printf("%lld\n",ans);
        return;
    }

    std::sort(C+1,C+1+n,cmp);

    for(int i=1;i<=n&&cnt[maxcnt]>(n/2);i++)
    {
        ans-=C[i].val[maxcnt];

        maxm=0;

        for(int j=1;j<=3;j++)
        {
            if(j==maxcnt)
                continue;

            maxm=max(C[i].val[j],maxm);
        }

        ans+=maxm,cnt[maxcnt]--;
    }

    printf("%lld\n",ans);
}

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    int T=read();

    while(T--)
        solve();

    return 0;
}

