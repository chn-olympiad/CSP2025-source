#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[4][100010],b[4][100010];
bool cmp(int x,int y)
{
    return a[1][x]-a[2][x]<a[1][y]-a[2][y];
}
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >>t;
    while(t--)
    {
        int n,cnt1=0,cnt2=0,cnt3=0,sum=0;
        cin >>n;
        for (int i=1;i<=n;i++)
        {
            cin >>a[1][i]>>a[2][i]>>a[3][i];
            int a1=a[1][i],a2=a[2][i],a3=a[3][i];
            a[1][i]=max({a1,a2,a3});
            a[3][i]=min({a1,a2,a3});
            a[2][i]=a1+a2+a3-a[1][i]-a[3][i];
            if(a[1][i]==a1) b[1][++cnt1]=i;
            else if(a[1][i]==a2) b[2][++cnt2]=i;
            else b[3][++cnt3]=i;
            sum+=a[1][i];
        }
        int maxn=0,y=max({cnt1,cnt2,cnt3});
        if(max({cnt1,cnt2,cnt3})==cnt1) maxn=1;
        else if(max({cnt1,cnt2,cnt3})==cnt2) maxn=2;
        else if(max({cnt1,cnt2,cnt3})==cnt3) maxn=3;
        sort(b[maxn]+1,b[maxn]+y+1,cmp);
        //cout<<sum<<" ";
        int p=1;
        while(y>n/2)
        {
            int now=b[maxn][p];
            sum-=a[1][now]-a[2][now];
            y--;p++;
        }
        cout<<sum<<"\n";
    }
    return 0;
}
