#include<bits/stdc++.h>
using namespace std;
int tpp,n,a[100005][4],t[4],b[100005][4],ans;
void check()
{
    if(t[1]>n/2)
    {
        while(t[1]>n/2)
        {
            int mi=1e9,xb;
            for(int i=1;i<=t[1];i++)
            {
                if(mi>a[b[i][1]][1]-max(a[b[i][1]][2],a[b[i][1]][3]))
                {
                    mi=a[b[i][1]][1]-max(a[b[i][1]][2],a[b[i][1]][3]);
                    xb=i;
                }
            }
            ans=ans-a[b[xb][1]][1]+max(a[b[xb][1]][2],a[b[xb][1]][3]);
            b[xb][1]=b[t[1]--][1];
        }
    }
    else if(t[2]>n/2)
    {
        while(t[2]>n/2)
        {
            int mi=1e9,xb;
            for(int i=1;i<=t[2];i++)
            {
                if(mi>a[b[i][2]][2]-max(a[b[i][2]][1],a[b[i][2]][3]))
                {
                    mi=a[b[i][2]][2]-max(a[b[i][2]][1],a[b[i][2]][3]);
                    xb=i;
                }
            }
            ans=ans-a[b[xb][2]][2]+max(a[b[xb][2]][1],a[b[xb][2]][3]);
            b[xb][2]=b[t[2]--][2];
        }
    }
    else if(t[3]>n/2)
    {
        while(t[3]>n/2)
        {
            int mi=1e9,xb;
            for(int i=1;i<=t[3];i++)
            {
                if(mi>a[b[i][3]][3]-max(a[b[i][3]][2],a[b[i][3]][1]))
                {
                    mi=a[b[i][3]][3]-max(a[b[i][3]][2],a[b[i][3]][1]);
                    xb=i;
                }
            }
            ans=ans-a[b[xb][3]][3]+max(a[b[xb][3]][2],a[b[xb][3]][1]);
            b[xb][3]=b[t[3]--][3];
        }
    }
    return;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>tpp;
    while(tpp--)
    {
        n=0;
        cin>>n;
        t[1]=0;
        t[2]=0;
        t[3]=0;
        ans=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            int q=max(a[i][1],max(a[i][2],a[i][3]));
            if(q==a[i][1])
            {
                b[++t[1]][1]=i;
                ans+=a[i][1];
            }
            else if(q==a[i][2])
            {
                b[++t[2]][2]=i;
                ans+=a[i][2];
            }
            else if(q==a[i][3])
            {
                b[++t[3]][3]=i;
                ans+=a[i][3];
            }
        }
        check();
        cout<<ans<<'\n';
    }
    return 0;
}
