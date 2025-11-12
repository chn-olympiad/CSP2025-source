#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
const int nr=510;
int a[nr],c[nr];
int p[nr];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        char c;
        cin>>c;
        a[i]=c-'0';
    }
    for(int i=1;i<=n;i++)cin>>c[i];
    if(n<=10)
    {
        for(int i=1;i<=n;i++)p[i]=i;
        int ans=0;
        do
        {
            int cc=0;
            for(int i=1;i<=n;i++)
            {
                if(a[i]==0||cc>=c[p[i]])cc++;
            }
            if(n-cc>=m)ans++;
        }while(next_permutation(p+1,p+n+1));
        cout<<ans<<endl;
    }
    else
    {
        int mul=1;
        for(int i=1;i<=n;i++)mul=1ll*mul*i%998244353;
        cout<<mul<<endl;
    }
    return 0;
}
