#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int T;
int n,ans;
int a[3][100005];
int id[3][100005],cnt[3];
int p;
bool cmp(int u,int v)
{
    return a[p][u]-max(a[(p+1)%3][u],a[(p+2)%3][u])<a[p][v]-max(a[(p+1)%3][v],a[(p+2)%3][v]);
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--)
    {
    cin>>n;
    cnt[0]=cnt[1]=cnt[2]=0;
    ans=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d",&a[0][i],&a[1][i],&a[2][i]);
        if(a[0][i]>a[1][i]&&a[0][i]>a[2][i])
            id[0][++cnt[0]]=i,ans+=a[0][i];
        else if(a[1][i]>=a[0][i]&&a[1][i]>a[2][i])
            id[1][++cnt[1]]=i,ans+=a[1][i];
        else
            id[2][++cnt[2]]=i,ans+=a[2][i];
    }
    p=-1;
    if(cnt[0]>n/2) p=0;
    else if(cnt[1]>n/2) p=1;
    else if(cnt[2]>n/2) p=2;
    // cout<<cnt[0]<<" "<<cnt[1]<<" "<<cnt[2]<<"\n";
    if(p==-1)
    {
        cout<<ans<<"\n";
        continue;
    }
    sort(id[p]+1,id[p]+1+cnt[p],cmp);
    for(int i=1;i<=cnt[p]-n/2;i++)
    {
        int u=id[p][i];
        // cout<<u<<" "<<a[p][u]<<" "<<max(a[(p+1)%3][u],a[(p+2)%3][u])<<" "<<a[p][u]-max(a[(p+1)%3][u],a[(p+2)%3][u])<<"\n";
        ans-=a[p][u]-max(a[(p+1)%3][u],a[(p+2)%3][u]);
    }
    cout<<ans<<"\n";
    }
    return 0;
}
