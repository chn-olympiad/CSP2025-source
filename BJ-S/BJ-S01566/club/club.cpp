#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int ak[100010][4],n,ans;
void dfs(int a,int b,int c,int anss)
{
    if(a+b+c==n)
    {
        /*
        cout<<endl;
        cout<<a<<" "<<b<<" "<<c<<endl;
        cout<<endl;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=3;j++)cout<<aka[i][j]<<" ";
            cout<<endl;
        }
        cout<<anss<<endl;
        */
        ans=max(ans,anss);
        return ;
    }
    if(a<n/2)
    {
        for(int i=1;i<=n;i++)
        {
            if(ak[i][1]==-1)continue;
            int aa=ak[i][1];
            int bb=ak[i][2];
            int cc=ak[i][3];
            ak[i][1]=-1;
            ak[i][2]=-1;
            ak[i][3]=-1;
            dfs(a+1,b,c,anss+aa);
            ak[i][1]=aa;
            ak[i][2]=bb;
            ak[i][3]=cc;
        }
    }
    if(b<n/2)
    {
        for(int i=1;i<=n;i++)
        {
            if(ak[i][1]==-1)continue;
            int aa=ak[i][1];
            int bb=ak[i][2];
            int cc=ak[i][3];
            ak[i][1]=-1;
            ak[i][2]=-1;
            ak[i][3]=-1;
            dfs(a,b+1,c,anss+bb);
            ak[i][1]=aa;
            ak[i][2]=bb;
            ak[i][3]=cc;
        }
    }
    if(c<n/2)
    {
        for(int i=1;i<=n;i++)
        {
            if(ak[i][1]==-1)continue;
            int aa=ak[i][1];
            int bb=ak[i][2];
            int cc=ak[i][3];
            ak[i][1]=-1;
            ak[i][2]=-1;
            ak[i][3]=-1;
            dfs(a,b,c+1,anss+cc);
            ak[i][1]=aa;
            ak[i][2]=bb;
            ak[i][3]=cc;
        }
    }

}
int main()
{
     freopen("club.in","r",stdin);
     freopen("club.out","w",stdout);
     ios::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);
     int t;
     cin>>t;
     while(t--)
     {
         cin>>n;
         ans=0;
         for(int i=1;i<=n;i++)cin>>ak[i][1]>>ak[i][2]>>ak[i][3];
         if(n>=100)
         {
             long long sum=0;
             sort(ak[1]+1,ak[1]+n+1);
             for(int i=n;i>=n/2;i--)sum+=(long long)ak[i];
             cout<<sum<<endl;
             continue;
         }
         dfs(0,0,0,0);
         cout<<ans<<endl;
     }
     return 0;
}
