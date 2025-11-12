#include<bits/stdc++.h>
using namespace std;
struct node
{
    int v,c;
}a[100001][4];
int dis12[100001],cnt[4];
int ans;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        memset(a,0,sizeof(a));
        ans=0;
        memset(dis12,0,sizeof(dis12));
        memset(cnt,0,sizeof(cnt));
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            a[i][1].c=1;
            a[i][2].c=2;
            a[i][3].c=3;
            cin>>a[i][1].v>>a[i][2].v>>a[i][3].v;
            if(a[i][1].v<a[i][2].v)swap(a[i][1],a[i][2]);
            if(a[i][1].v<a[i][3].v)swap(a[i][1],a[i][3]);
            if(a[i][2].v<a[i][3].v)swap(a[i][2],a[i][3]);
            dis12[i]=a[i][1].v-a[i][2].v;
            cnt[a[i][1].c]++;
            ans+=a[i][1].v;
        }
        sort(dis12+1,dis12+n+1);
        //for(int i=1;i<=n;i++)cout<<dis12[i];
        if(cnt[1]>n/2||cnt[2]>n/2||cnt[3]>n/2)
        {
            int x=max({cnt[1],cnt[2],cnt[3]})-n/2;
            for(int i=1;i<=x;i++)
            {
                ans-=dis12[i];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
