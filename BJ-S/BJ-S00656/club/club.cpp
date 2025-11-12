#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int t,n,a[N][3],f[N],cnt[N];
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--)
    {
        int fl[3],ans=0,flag=-1,pos=0;
        fl[0]=fl[1]=fl[2]=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i][0]>>a[i][1]>>a[i][2];
            if(a[i][0]>=a[i][1] && a[i][0]>=a[i][2]) ans+=a[i][0],fl[0]++,f[i]=0;
            else if(a[i][1]>=a[i][0] && a[i][1]>=a[i][2]) ans+=a[i][1],fl[1]++,f[i]=1;
            else ans+=a[i][2],fl[2]++,f[i]=2;
            cnt[i]=0;
        }
        if(fl[0]>n/2) flag=0;
        if(fl[1]>n/2) flag=1;
        if(fl[2]>n/2) flag=2;
        if(flag==-1)
        {
            cout<<ans<<endl;
            continue;
        }
        for(int i=1;i<=n;i++) if(f[i]==flag) cnt[++pos]=a[i][flag]-max(a[i][(flag+1)%3],a[i][(flag+2)%3]);
        sort(cnt+1,cnt+pos+1);
        for(int i=1;i<=fl[flag]-n/2;i++) ans-=cnt[i];
        cout<<ans<<endl;
    }
    return 0;
}
