#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[100005];
int a2[100005][25];
int k2[25];
int o2[25];
int ans2;
int e[100005];
struct l
{
    int l,r,s;
}num[100005];
int ans;
bool cmp(l a,l b)
{
    return a.s>=b.s;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        int o=1;
        while(a[i])
        {
            if(a[i]%2)a2[i][o]++;
            a[i]/=2;
            o++;
        }
        for(int j=1;j<=20;j++)
        {
            a2[i][j]+=a2[i-1][j];
        }
    }
    int o=1;
    while(k)
    {
        if(k%2)k2[o]++;
        k/=2;
        o++;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            bool b=1;
            for(int o=1;o<=20;o++)
            {
                o2[o]=abs(a2[j][o]-a2[i-1][o]);
                if(o2[o]%2!=k2[o])b=0,o=20;
            }
            if(b)ans++,num[ans].l=i,num[ans].r=j,num[ans].s=num[ans].r-num[ans].l+1;
        }
    }
    sort(num+1,num+ans+1,cmp);
    ans2=ans;
    /*for(int i=1;i<=ans;i++)
    {
        int ll=num[ans].l,rr=num[ans].r;
        for(int j=ll;j<=rr;j++)
        {
            if(e[j]==1)
            {
                for(int u=j;u>=ll;u--)
                {
                    e[u]=0;
                }
                j=rr;
                ans2--;
            }
            else
            {
                e[j]=1;
            }
        }
    }*/
    cout<<ans2;
    return 0;
}
