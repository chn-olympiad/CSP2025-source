#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int xxx=1;xxx<=t;xxx++)
    {
        int n;
        map<int,int> mp1;
        map<int,int> mp2;//mp1为人在那个c,2为每个c有几个人
        cin>>n;
        int a[100005];
        int b[100005];
        int c[100005];
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i]>>b[i]>>c[i];
            int khy=max(a[i],max(b[i],c[i]));
            ans+=khy;
            if(khy==a[i])
            {
                mp1[i]=1;
                mp2[1]++;
            }
            else if(khy==b[i])
            {
                mp1[i]=2;
                mp2[2]++;
            }
            else
            {
                mp1[i]=3;
                mp2[3]++;
            }
        }
        if(mp2[1]<=n/2 && mp2[2]<=n/2 && mp2[3]<=n/2)
        {
            cout<<ans<<endl;
            continue;
        }
        int ybx[100005];
        int biaoji=0;
        if(mp2[1]>n/2)//第一种情况，club1人数最多
        {
            for(int i=1;i<=n;i++)
            {
                if(mp1[i]==1)
                {
                    biaoji++;
                    ybx[biaoji]=a[i]-max(b[i],c[i]);
                }
            }
            sort(ybx+1,ybx+1+biaoji);
            int ttt=mp2[1]-n/2;
            for(int i=1;i<=ttt;i++)
            {
                ans-=ybx[i];
            }
            cout<<ans<<endl;
            continue;
        }
        else if(mp2[2]>n/2)//第一种情况，club1人数最多
        {
            for(int i=1;i<=n;i++)
            {
                if(mp1[i]==2)
                {
                    biaoji++;
                    ybx[biaoji]=b[i]-max(a[i],c[i]);
                }
            }
            sort(ybx+1,ybx+1+biaoji);
            int ttt=mp2[2]-n/2;
            for(int i=1;i<=ttt;i++)
            {
                ans-=ybx[i];
            }
            cout<<ans<<endl;
        }
        else if(mp2[3]>n/2)//第一种情况，club1人数最多
        {
            for(int i=1;i<=n;i++)
            {
                if(mp1[i]==3)
                {
                    biaoji++;
                    ybx[biaoji]=c[i]-max(a[i],b[i]);
                }
            }
            sort(ybx+1,ybx+1+biaoji);
            int ttt=mp2[3]-n/2;
            for(int i=1;i<=ttt;i++)
            {
                ans-=ybx[i];
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
