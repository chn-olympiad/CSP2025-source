#include<bits/stdc++.h>
using namespace std;
int f[100005][5],a[100005][5],T,n,num[5],ans,pf1[100005];
/*int dfs(int ly)
{
    if(ly==n)
    {
          ans
    }
    for(int i=1;i<=3;i++)
    {
          if(num[i]+1<=n/2)
          {
                num[i]++;
                ly++;
                ans+=a[ly][i];
                dfs(ly);
                num[i]--;
                ly--;

          }
    }
}*/
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--)
    {
        memset(f,-1,sizeof(f));
        num[1]=num[2]=num[3]=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            if(a[i][2]==0&&a[i][3]==0)
            {
                pf1[i]=a[i][1];
            }

        }

        sort(pf1+1,pf1+n+1);

        long long sum=0;
        for(int i=n;i>=n/2+1;i--)
        {
            sum+=pf1[i];
        }
        cout<<sum;
    }

    return 0;
}
