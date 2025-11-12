#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define N 100005
int n,cnt[5];
int a[N][4];
int b[N];

void solve()
{
    memset(cnt,0,sizeof cnt);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i][1]>>a[i][2]>>a[i][3];
    }
    int ans=0;
    bool adj=0;
    int adji;
    for(int i=1;i<=n;i++)
    {
        int maxi;
        if(a[i][1]>=a[i][2] && a[i][1]>=a[i][3])
            maxi=1;
        else if(a[i][2]>=a[i][1] && a[i][2]>=a[i][3])
            maxi=2;
        else maxi=3;
        if(cnt[maxi]<n/2)
            cnt[maxi]++,ans+=a[i][maxi];
        else
            {
                adj=1;
                adji=maxi;
                break;
            }
    }
    if(!adj){
        cout<<ans<<endl;
        return;
    }
    ans=0;
    int ct=0;
    for(int i=1;i<=n;i++)
    {
        int maxi;
        if(a[i][1]>=a[i][2] && a[i][1]>=a[i][3])
            maxi=1;
        else if(a[i][2]>=a[i][1] && a[i][2]>=a[i][3])
            maxi=2;
        else maxi=3;
        ans+=a[i][maxi];
        if(maxi==adji)
        {
            ct++;
            int cha=1000000;
            for(int j=1;j<=3;j++)
            {
                if(j==maxi)continue;
                cha=min(cha,a[i][maxi]-a[i][j]);
            }
            b[ct]=cha;
        }
    }
    sort(b+1,b+ct+1);
    for(int i=1;i<=ct-n/2;i++)
        ans-=b[i];
    cout<<ans<<endl;
}



int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
