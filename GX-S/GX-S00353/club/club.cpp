#include<bits/stdc++.h>
using namespace std;
int T,n;
int a[3+5][200000+10];
int t2,t3;
int ans=0;
int mx;
void dfs(int x,int t1,int t2,int t3,int tm)
{
    //cout<<"OUT:"<<x<<" "<<t1<<" "<<t2<<" "<<t3<<" "<<tm<<"\n";
    if(x==n+1)
    {
        //cout<<"UPD:"<<x<<" "<<t1<<" "<<t2<<" "<<t3<<" "<<tm<<"\n";
        ans=max(ans,tm);
    }
    if(t1<mx)
    {
        dfs(x+1,t1+1,t2,t3,tm+a[1][x]);
    }
    if(t2<mx)
    {
        dfs(x+1,t1,t2+1,t3,tm+a[2][x]);
    }
    if(t3<mx)
    {
        dfs(x+1,t1,t2,t3+1,tm+a[3][x]);
    }
}

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=3;++j)
            {
                scanf("%d",&a[j][i]);
            }
            t2+=a[2][i];
            t3+=a[3][i];
        }
        mx=n/2;
        ans=0;
        if(t2==0 and t3==0)
        {
            sort(a[1]+1,a[1]+1+n,less<int>());
            for(int i=1;i<=mx;++i)ans+=a[1][i];
        }
        dfs(1,0,0,0,0);
        printf("%d\n",ans);
    }
    return 0;
}
