#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n,cnt[5];
struct node
{
    int mx,tp,c;
}a[100005];
bool cmp(node x,node y)
{
    return x.c<y.c;
}
signed main()
{
    cin.tie(0);cout.tie(0);
    ios::sync_with_stdio(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cnt[1]=cnt[2]=cnt[3]=0;
        for(int i=1;i<=n;i++)
        {
            int x,y,z;
            cin>>x>>y>>z;
            if(x>=y&&y>=z) a[i]={x,1,x-y},cnt[1]++;
            else if(x>=z&&z>=y) a[i]={x,1,x-z},cnt[1]++;
            else if(y>=x&&x>=z) a[i]={y,2,y-x},cnt[2]++;
            else if(y>=z&&z>=x) a[i]={y,2,y-z},cnt[2]++;
            else if(z>=x&&x>=y) a[i]={z,3,z-x},cnt[3]++;
            else if(z>=y&&y>=x) a[i]={z,3,z-y},cnt[3]++;
        }
        sort(a+1,a+1+n,cmp);
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            ans+=a[i].mx;
            //cout<<a[i].mx<<' '<<a[i].tp<<' '<<a[i].c<<' '<<ans<<endl;
            if(cnt[a[i].tp]<=n/2) continue;
            ans-=a[i].c;cnt[a[i].tp]--;
        }
        cout<<ans<<endl;
    }
    return 0;
}
