#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=100050;
int T,n;
int cnt[5],a[N][5],d[N],chs[N];
ll ans;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>T;
    while(T--)
    {
        memset(cnt,0,sizeof(cnt));
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]) cnt[1]++,chs[i]=1;
            else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]) cnt[2]++,chs[i]=2;
            else if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2]) cnt[3]++,chs[i]=3;
            ans+=max(a[i][1],max(a[i][2],a[i][3]));
        }
        if(cnt[1]<=n/2&&cnt[2]<=n/2&&cnt[3]<=n/2)
        {
            cout<<ans<<'\n';
        }
        else
        {
            int extra,lingwai1,lingwai2;
            if(cnt[1]>cnt[2]&&cnt[1]>cnt[3]) extra=1,lingwai1=2,lingwai2=3;
            if(cnt[2]>cnt[1]&&cnt[2]>cnt[3]) extra=2,lingwai1=1,lingwai2=3;
            if(cnt[3]>cnt[1]&&cnt[3]>cnt[2]) extra=3,lingwai1=1,lingwai2=2;
            int x=0;
            for(int i=1;i<=n;i++)
            {
                if(chs[i]==extra)
                {
                    d[++x]=a[i][extra]-max(a[i][lingwai1],a[i][lingwai2]);
                }
            }
            sort(d+1,d+x+1);
            int k=1;
            while(cnt[extra]>n/2)
            {
                ans-=d[k];
                k++;
                cnt[extra]--;
            }
            cout<<ans<<'\n';
        }
    }
    return 0;
}
