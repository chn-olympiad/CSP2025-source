#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
const int maxn=1e5+10;
int n;
int a[maxn][5];
int mx1[maxn],mx2[maxn],d[maxn];
int cnt[10];
int bl[maxn];
vector<int> vec[3];
void sol()
{
    cin>>n;
    for(int i=1;i<=n;i++) mx1[i]=mx2[i]=d[i]=0,bl[i]=-1;
    cnt[0]=cnt[1]=cnt[2]=cnt[3]=0;
    vec[0].clear(),vec[1].clear(),vec[2].clear();
    for(int i=1;i<=n;i++) cin>>a[i][0]>>a[i][1]>>a[i][2];
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int t=max(max(a[i][0],a[i][1]),a[i][2]);
        int pos=0;
        for(int j=0;j<3;j++)
        {
            if(a[i][j]==t)
            {
                cnt[j]++;
                pos=j;
                break;
            }
        }
        bl[i]=pos;
        ans+=t;
    }
    int c=max(max(cnt[0],cnt[1]),cnt[2]);
	for(int i=1;i<=n;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(a[i][j]>mx1[i]) mx2[i]=mx1[i],mx1[i]=a[i][j];
            else mx2[i]=max(mx2[i],a[i][j]);
        }
        vec[bl[i]].push_back(mx1[i]-mx2[i]);
    }
    for(int i=0;i<3;i++) sort(vec[i].begin(),vec[i].end());
    for(int i=0;i<3;i++)
    {
        if(cnt[i]<=n/2) continue;
        for(int j=1;j<=cnt[i]-n/2;j++) ans-=vec[i][j-1];
    }
    cout<<ans<<endl;
}
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--) sol();
	return 0;
}
