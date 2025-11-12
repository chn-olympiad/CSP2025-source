#include<bits/stdc++.h>
using namespace std;
long long n,t,Max=0;
long long l1[100005],l2[100005],l3[100005];
void dfs(long long step=0,long long ans=0,long long len1=0,long long len2=0,long long len3=0)
{
    if(step > n)
    {
        Max = max(ans,Max);
        return;
    }
    else
    {
        if(len1<n/2) dfs(step+1,ans+l1[step],len1+1,len2,len3);
        if(len2<n/2) dfs(step+1,ans+l2[step],len1,len2+1,len3);
        if(len3<n/2) dfs(step+1,ans+l3[step],len1,len2,len3+1);
    }
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(long long j=1;j<=t;j++)
    {
        cin>>n;
        memset(l1,0,sizeof(l1));
        memset(l2,0,sizeof(l2));
        memset(l3,0,sizeof(l3));
        Max=0;
        for(long long i=1;i<=n;i++) cin>>l1[i]>>l2[i]>>l3[i];
        dfs();
        cout<<Max<<endl;
    }
    return 0;
}
