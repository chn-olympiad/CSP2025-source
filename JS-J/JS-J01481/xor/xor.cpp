#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[100005],h[100005];
map<int,vector<int> > mp;
int ans=0;
void dg(int dep,int gs,int tot,int choose)
{
    if(dep>n)
    {
        if(tot==k&&choose!=0)
        {
            gs++;
        }
        ans=max(ans,gs);
        return;
    }
    if(tot==k&&choose!=0)
    {
        gs++;
        choose=0;
    }
    if(choose==0)
    {
        dg(dep+1,gs,0,0);
        dg(dep+1,gs,a[dep],1);
    }
    else dg(dep+1,gs,tot^a[dep],1);
}
void dg2(int dep,int gs)
{
    if(dep>n)
    {
        ans=max(ans,gs);
    }
    if(!mp.count(dep))
    {
        ans=max(ans,gs);
        return;
    }
    for(int i=0;i<mp[dep].size();i++)
    {
        dg2(mp[dep][i]+1,gs+1);
    }
    dg2(dep+1,gs);
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        h[i]=h[i-1]^a[i];
        if(a[i]==1)
        {
            sum++;
        }
        else if(a[i]!=0)
        {
            sum=INT_MIN;
        }
    }
    if(k<=1&&sum>0)
    {
        cout<<sum;
        return 0;
    }
    if(n<50)
    {
        dg(1,0,0,0);
        cout<<ans;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if((h[j]^h[i-1])==k)
            {
                if(!mp.count(i))
                {
                    vector<int> v;
                    mp[i]=v;
                }
                mp[i].push_back(j);
            }
        }
    }
    dg2(1,0);
    cout<<ans;
    return 0;

    return 0;
}
