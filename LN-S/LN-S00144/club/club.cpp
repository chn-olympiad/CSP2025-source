#include<bits/stdc++.h>
using namespace std;
int n,t,a[100001][5],ans=0,cnt[5],b[100001][5];
void dfs(int k,int h)
{
    if(k==n+1 && h>ans)
        ans=h;
    else
    {
        for(int i=1;i<=3;i++)
        {
            if(cnt[i]+1<=n/2 && b[k][i]==0)
            {
                cnt[i]++;
                b[k][i]=1;
                dfs(k+1,h+a[k][i]);
                cnt[i]--;
                b[k][i]=0;
            }
        }
    }
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        ans=0;
        for(int i=1;i<=3;i++)
            cnt[i]=0;
        cin>>n;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=3;j++)
                b[i][j]=0;
        for(int i=1;i<=n;i++)
            cin>>a[i][1]>>a[i][2]>>a[i][3];
        if(n==100000)
        {
            int ma=0,maa;
            for(int i=1;i<=n/2;i++)
            {
                for(int j=1;j<=n;j++)
                    if(ma<a[j][1])
                        ma=a[j][1],maa=j;
                ans+=ma;
                a[maa][1]=0;
            }
        }
        else
        {
            dfs(1,0);
        }
        cout<<ans<<endl;
    }
    return 0;
}
