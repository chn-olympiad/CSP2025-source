#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,a[100005],b[100005],c[100005],ans,maxp;
unordered_map<ll,int>mpa,mpb;//值and下标
bool cmp(ll a,ll b)
{
    return a>b;
}
void dfs(ll p,ll pa,ll pb,ll pc,ll sum)
{
    if(pa>maxp||pb>maxp||pc>maxp)
    {
        return;
    }
    if(p==n)
    {
        ans=max(ans,sum);
        return;
    }
    dfs(p+1,pa+1,pb,pc,sum+a[p+1]);
    dfs(p+1,pa,pb+1,pc,sum+b[p+1]);
    dfs(p+1,pa,pb,pc+1,sum+c[p+1]);
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        ll fb=1,fc=1;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i]>>b[i]>>c[i];
            if(b[i])fb=0;
            if(c[i])fc=0;
        }
        if(fb==1&&fc==1)
        {
            ll sum=0;
            sort(a+1,a+n+1,cmp);
            for(int i=1;i<=n/2;i++)
            {
                sum+=a[i];
            }
            cout<<sum<<endl;
        }/*
        else if(fc==1)
        {
            ll sum=0;
            for(int i=1;i<=n;i++)
            {
                mpa[a[i]]=i;
                mpb[b[i]]=i;
            }
            sort(a+1,a+n+1,cmp);
            sort(b+1,b+n+1,cmp);
            int pera=0,perb=0;
            for(int i=1;i<=n;i++)
            {
                if(a[i]>b[mpa[a[i]]]&&pera<=n/2)
                {
                    sum+=a[i];
                    pera++;
                }
                else
                {
                    sum+=b[i];
                    perb++;
                }
            }
            cout<<sum<<endl;
        }*/
        else
        {
            maxp=n/2;
            dfs(0,0,0,0,0);
            cout<<ans<<endl;
            ans=0;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
