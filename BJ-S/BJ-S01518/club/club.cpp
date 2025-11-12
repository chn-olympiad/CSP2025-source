#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

const int inf=1e9+9;
const int N=1e5+9;
int a[N],b[N],c[N],d[N];
int n;
const int M=30+9;
int f[M][M][M][M];

const int K=200+9;
int f2[K][K][K];

void solved2()
{
    for(int i1=1;i1<=n;i1++) for(int i2=0;i2<=n;i2++) for(int i3=0;i3<=n;i3++) f2[i1][i2][i3]=-inf;

    f2[1][1][0]=a[1];
    f2[1][0][1]=b[1];
    int ans=0;
    for(int i=2;i<=n;i++)
    {
        for(int j1=0;j1<=n/2;j1++) for(int j2=0;j2<=n/2;j2++)
        {
            f2[i][j1][j2]=-inf;
            if(j1>0) f2[i][j1][j2]=max(f2[i][j1][j2],f2[i-1][j1-1][j2]+a[i]);
            if(j2>0) f2[i][j1][j2]=max(f2[i][j1][j2],f2[i-1][j1][j2-1]+b[i]);
            ans=max(ans,f2[i][j1][j2]);
        }
    }

    cout << ans << endl ;

    return ;
}
void solved1()
{
    for(int i1=1;i1<=n;i1++) for(int i2=0;i2<=n;i2++) for(int i3=0;i3<=n;i3++) for(int i4=0;i4<=n;i4++) f[i1][i2][i3][i4]=-inf;
    f[1][1][0][0]=a[1];
    f[1][0][1][0]=b[1];
    f[1][0][0][1]=c[1];

    int ans=0;
    for(int i=2;i<=n;i++)
    {
        for(int j1=0;j1<=n/2;j1++) for(int j2=0;j2<=n/2;j2++) for(int j3=0;j3<=n/2;j3++)
        {
            if(j1+j2+j3>n) continue;
            if(j1>=1) f[i][j1][j2][j3]=max(f[i][j1][j2][j3],f[i-1][j1-1][j2][j3]+a[i]);
            if(j2>=1) f[i][j1][j2][j3]=max(f[i][j1][j2][j3],f[i-1][j1][j2-1][j3]+b[i]);
            if(j3>=1) f[i][j1][j2][j3]=max(f[i][j1][j2][j3],f[i-1][j1][j2][j3-1]+c[i]);
            ans=max(ans,f[i][j1][j2][j3]);
        }
    }

    cout << ans << endl ;

    return ;
}
void solved3()
{
    for(int i=1;i<=n;i++) d[i]=a[i];

    sort(d+1,d+n+1);

    int ans=0;
    for(int i=n;i>n/2;i--) ans+=d[i];

    cout << ans << endl ;

    return ;
}
void solved()
{
    cin >> n ;
    for(int i=1;i<=n;i++) cin >> a[i] >> b[i] >> c[i] ;

    if(n<=30)
    {
        solved1();
        return ;
    }

    int mx3=0,mx2=0;
    for(int i=1;i<=n;i++) mx2=max(mx2,b[i]),mx3=max(mx3,c[i]);
    if(mx2==0&&mx3==0)
    {
        solved3();
        return ;
    }

    int mmx=0;
    for(int i=1;i<=n;i++) mmx=max(mmx,c[i]);
    if(n<=200&&mmx==0)
    {
        solved2();
        return ;
    }

    return ;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;  cin >> t ;  while(t--)
    solved();

    return 0;
}
