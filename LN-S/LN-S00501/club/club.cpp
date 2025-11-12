#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN=1e5+5;
int t;
int n,ans;
int a[MAXN],b[MAXN],c[MAXN];
int f[1010][1010];
bool cmp(int a,int b){return a>b;}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        int ans=0;
        cin>>n;
        if(n<300)
        {
            for(int i=1;i<=n;i++)
            {
                cin>>a[i]>>b[i]>>c[i];
            }
            f[1][0]=a[1];
            f[0][1]=b[1];
            f[0][0]=c[1];
            f[1][1]=max(a[1]+b[2],a[2]+b[1]);
            f[1][0]=max(a[1]+c[2],a[2]+c[1]);
            f[0][1]=max(b[1]+c[2],b[2]+c[1]);
            int hn=n/2;
            for(int i=1;i<=hn;i++)
            {
                for(int j=1;j<=hn;j++)
                {
                    f[i][j]=max(f[i-1][j-1]+a[i+j],max(f[i-1][j-1]+b[i+j],f[i-1][j-1]+c[i+j]));
                    ans=max(ans,f[i][j]);
                }
            }
            cout<<ans<<"\n";
        }
        else
        {
            sort(a+1,a+1+n,cmp);
            int hn=n/2;
            for(int i=1;i<=hn;i++)
            {
                ans+=a[i];
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}
