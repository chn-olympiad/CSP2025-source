#include <bits/stdc++.h>
using namespace std;
int t,n,a[100001][3],ans;
void ssa ()
{
    int cnt[100001];
    for (int i=1;i<=n;i++)
    {
        cnt[i]=a[i][0];
    }
    sort(cnt+1,cnt+n+1);
    for (int i=n;i>n/2;i--)
    {
        ans+=cnt[i];
    }
    cout << ans << endl;
}
void ssb ()
{
    pair <int,int> cnt1[100001],cnt2[100001];
    int pn0=0,pn1=0;
    for (int i=1;i<=n;i++)
    {
        if (a[i][0]>=a[i][1])
        {
            cnt1[++pn0].first=a[i][0];
            cnt1[pn0].second=i;
        }
        else
        {
            cnt2[++pn1].first=a[i][1];
            cnt2[pn1].second=i;
        }
    }
    if (pn0>n/2)
    {
        sort(cnt1+1,cnt1+pn0+1);
        for (int i=1;i<=pn0;i++)
        {
            if (i<=pn0-n/2)
            {
                ans+=a[cnt1[i].second][1];
            }
            else
            {
                ans+=a[cnt1[i].second][0];
            }
        }
        for (int i=1;i<=pn1;i++)
        {
            ans+=cnt2[i].first;
        }
    }
    else if (pn1>n/2)
    {
        sort(cnt2+1,cnt2+pn1+1);
        for (int i=1;i<=pn1;i++)
        {
            if (i<=pn1-n/2)
            {
                ans+=a[cnt2[i].second][0];
            }
            else
            {
                ans+=a[cnt2[i].second][1];
            }
        }
        for (int i=1;i<=pn0;i++)
        {
            ans+=cnt1[i].first;
        }
    }
    else
    {
        for (int i=1;i<=pn0;i++)
        {
            ans+=cnt1[i].first;
        }
        for (int i=1;i<=pn1;i++)
        {
            ans+=cnt2[i].first;
        }
    }
    cout << ans << endl;
}
void nass ()
{
    for (int i=1;i<=n;i++)
    {
        if (a[i][0]>=a[i][1]&&a[i][0]>=a[i][2])
        {
            ans+=a[i][0];
        }
        else if (a[i][1]>=a[i][0]&&a[i][1]>=a[i][2])
        {
            ans+=a[i][1];
        }
        else
        {
            ans+=a[i][2];
        }
    }
    cout << ans << endl;
}
int main ()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--)
    {
        ans=0;
        int aia01=true,aia02=true;
        cin >> n;
        for (int i=1;i<=n;i++)
        {
            cin >> a[i][0] >> a[i][1] >> a[i][2];
            if (a[i][1]!=0)
            {
                aia01=false;
            }
            if (a[i][2]!=0)
            {
                aia02=false;
            }
        }
        if (aia01&&aia02)
        {
            ssa();
        }
        else if (aia02)
        {
            ssb();
        }
        else
        {
            nass();
        }
    }
    return 0;
}
