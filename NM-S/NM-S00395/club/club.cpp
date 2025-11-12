#include<bits/stdc++.h>
using namespace std;
int an[5][100005];
int ans;
bool vis[100005];
int A[100005],B[100005]; 
void dfs(int i,int n,int t,int deeth,int a,int b,int c)
{
    if(deeth==n)
    {
        ans=max(ans,t);
    }
    for(int j=1;j<=n;j++)
    {
        if(vis[j]==0)
        {
            vis[j]=1;
            int lim=n>>1;
            if(a<lim)
            {
                dfs(j,n,t+an[1][j],deeth+1,a+1,b,c);
            }
            if(b<lim)
            {
                dfs(j,n,t+an[2][j],deeth+1,a,b+1,c);
            }
            if(c<lim)
            {
                dfs(j,n,t+an[3][j],deeth+1,a,b,c+1);
            }
            vis[j]=0;
        }
    }
}
bool chak1()
{
    for(int i=0;i<1000;i++)
    {
        if(an[2][i]!=0||an[3][i]!=0)
        {
            return 0;
        }
    }
    return 1;
}
bool chak2()
{
    for(int i=0;i<1000;i++)
    {
        if(an[3][i]!=0)
        {
            return 0;
        }
    }
    return 1;
}
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
     freopen("club.in","r",stdin);
     freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T=0;
    cin>>T;
    while(T--)
    {
        memset(an,0,sizeof (an));
        int n=0;
        cin>>n;

        int a,b,c;
		memset(A,0,sizeof(A));
		memset(B,0,sizeof(B));
        for(int i=1;i<=n;i++)
        {
            cin>>a>>b>>c;
            an[1][i]=a;
            an[2][i]=b;
            an[3][i]=c;
            A[i]=a;
            B[i]=b;
            
        }
       	if(n<200)
       	{
       		ans=-100;
        dfs(1,n,0,0,0,0,0);        
        cout<<ans<<endl;
		   }
            if(chak1())
            {
                cout<<0;
            }
        
        
    }
    return 0;
}