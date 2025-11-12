#include<bits/stdc++.h>
using namespace std;
int n,m,k,cnt;
int a[100000],v[100000],man[100000];
void dfs(int s,int ma,int p,int fa)
{
    if(p>=3&&s>ma*2)  cnt++;
    for(int i=fa+1;i<=n;i++)
    {
        if(v[i]==0)
        {
            v[i]=1;
            if(a[i]>ma)
            {
                man[p]=ma;
                ma=a[i];
            }
            dfs(s+a[i],ma,p+1,i);
            v[i]=0;
            ma=man[p];
        }
    }
    return;
}
int ans=0;
signed main()
{
   freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n<=20)
    {
        dfs(0,0,0,0);
         cout<<cnt;
        return 0;
    }
    else{
        for(int i=4;i<=n;i++)
        {
            int bb=1;
            for(int j=i-1;j>=0;j--)
            {
                bb=bb*(n-j);
            }
            bb=bb/i;
            ans+=bb;
        }
        cout<<ans;
        return 0;
    }

}
