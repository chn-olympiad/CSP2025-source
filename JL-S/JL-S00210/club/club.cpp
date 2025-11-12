#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+1145;
int t,n,ans,cnt,a[N][5],b[5],mx[N],c[N],f[N];
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;b[1]=b[2]=b[3]=ans=0;cnt=0;
        for(int i=1;i<=n;i++)mx[i]=-1,f[N]=0,c[i]=1145141919;
        for(int i=1;i<=n;i++)
        {

            for(int j=1;j<=3;j++)
            {
                cin>>a[i][j];
                if(a[i][j]>mx[i])mx[i]=a[i][j],f[i]=j;
            }
            ans+=mx[i];b[f[i]]++;
        }
        int x=0;
        if(b[1]>n/2)x=1;
        if(b[2]>n/2)x=2;
        if(b[3]>n/2)x=3;
        if(!x){cout<<ans<<endl;continue;}
        for(int i=1;i<=n;i++)
        {
            if(f[i]!=x)continue;++cnt;
            if(x!=1)c[cnt]=min(c[cnt],a[i][x]-a[i][1]);
            if(x!=2)c[cnt]=min(c[cnt],a[i][x]-a[i][2]);
            if(x!=3)c[cnt]=min(c[cnt],a[i][x]-a[i][3]);
        }
        sort(c+1,c+1+cnt);
        for(int i=1;i<=b[x]-n/2;i++)
        {
            ans-=c[i];
        }
        cout<<ans<<endl;
    }

    return 0;
}
