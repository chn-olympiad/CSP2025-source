#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int N=2e5+10;
int a[N],b[N],c[N],d[N],tp,ans;
void run()
{
    int n,cnt1=0,cnt2=0,cnt3=0;
    cin>>n;
    tp=ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
        if(a[i]>=b[i]&&a[i]>=c[i])
        {
            cnt1++;
            ans+=a[i];
        }
        else if(b[i]>=c[i])
        {
            cnt2++;
            ans+=b[i];
        }
        else
        {
            cnt3++;
            ans+=c[i];
        }
    }
    int cnt=0;
    if(cnt1>n/2)
    {
        cnt=cnt1-n/2;
        for(int i=1;i<=n;i++)
        {
            if(a[i]>=b[i]&&a[i]>=c[i])
            {
                d[++tp]=a[i]-max(b[i],c[i]);
            }
        }
    }
    else if(cnt2>n/2)
    {
        cnt=cnt2-n/2;
        for(int i=1;i<=n;i++)
        {
            if(b[i]>=a[i]&&b[i]>=c[i])
            {
                d[++tp]=b[i]-max(a[i],c[i]);
            }
        }
    }
    else if(cnt3>n/2)
    {
        cnt=cnt3-n/2;
        for(int i=1;i<=n;i++)
        {
            if(c[i]>=a[i]&&c[i]>=b[i])
            {
                d[++tp]=c[i]-max(a[i],b[i]);
            }
        }
    }
    sort(d+1,d+tp+1);
    for(int i=1;i<=cnt;i++)ans-=d[i];
    cout<<ans<<endl;
}
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)run();
    return 0;
}