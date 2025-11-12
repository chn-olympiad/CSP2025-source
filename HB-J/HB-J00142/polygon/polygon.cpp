#include<bits/stdc++.h>
using namespace std;
int len[5004],place[5004],n;
bool used[5004];
long long ans=0;
const long long mmod=998244353;
void put(int maxdeep,int t,int start)
{
    if(t>maxdeep)
    {
        long long sum=0;
        int maxx=0;
        for(int i=1;i<=maxdeep;i++)
        {
            sum+=len[place[i]];
            maxx=max(maxx,len[place[i]]);
        }
        if(sum>2*maxx)
            ans=(ans+1)%mmod;
        return;
    }
    for(int i=start;i<=n;i++)
    {
        if(!used[i])
        {
            used[i]=1;
            place[t]=i;
            put(maxdeep,t+1,i+1);
            used[i]=0;
        }
    }
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>len[i];
        sort(len+1,len+n+1);
    for(int i=3;i<=n;i++)
        put(i,1,1);
    cout<<ans;
    return 0;
}
