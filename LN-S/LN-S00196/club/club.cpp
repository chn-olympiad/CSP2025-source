#include<bits/stdc++.h>
using namespace std;
int n;
const int N=1e5+5;
int a[N][5];
int t;
bool vis[N][5];
int maxx[N];
int sum;
int cnt[N];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>t;
    while(t--)
    {
        cin>>n;
        memset(cnt,0,sizeof(cnt));
        memset(maxx,0,sizeof(maxx));
        sum=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=3;j++)
            {
                cin>>a[i][j];
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=3;j++)
            {
                maxx[i]=max(maxx[i],a[i][j]);
            }
        }
        for(int i=1;i<=n;i++)
        {
            sum+=maxx[i];
        }
        cout<<sum<<'\n';
    }
    return 0;
}