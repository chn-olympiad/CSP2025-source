#include<bits/stdc++.h>
using namespace std;
struct node
{

    int shu;
    int id;
    bool flag=0;
}h[100010][3];
bool cmp(node x,node y)
{
    return x.shu>y.shu;

}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(n==2)
        {
            int a,b,c,d,e,f;
            cin>>a>>b>>c>>d>>e>>f;
            int h1=a+e,h2=a+f,h3=b+d,h4=b+f,h5=c+d,h6=c+e;
            cout<<max(h1,max(h2,max(h3,max(h4,max(h5,h6)))))<<endl;
        }
        else
        {
            int ans=0;
            for(int i=1;i<=n;i++)
            {

                int a,b,c;
                cin>>a>>b>>c;
                ans+=max(a,max(b,c));
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}

//Ren5Jie4Di4Ling5%
/*#include<bits/stdc++.h>
using namespace std;
int h[10010][5];//,h2[10010][5],h3[10010][5];
int dp[1510][4][4];
void bfs(int x,int y,int a,int b,int c)
{
    for(int i=1;i<=3;i++)
    {
        if(i==1&&a!=0)
        {
            a--;
            for(int j=1;j<=3;j++)
                dp[x][y]=dp[x-1][j];

        }

    }
    if()
    bfs(x-1,)
    for(int i=2;i<=n;i++)
        {

            for(int j=1;j<=3;j++)
            {
                dp[i][j]=dp[i-1][j];
                if(j==1)
                {
                    for(int w=1;w<=a;w++)
                    {
                        //if(w>1)
                        dp[i][1][w]=max(dp[i-1][1][w-1]+h[i][j],dp[i][j]);
                    }


                }

            }
        }

}
int main()
{
    int t;
    //cin>>t;
    //while(t--)
    //{
        int n;
        cin>>n;
        int l=n/2;
        int a=l,b=l,c=l;//-----------------
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=3;j++)
                cin>>h[i][j]>>h[i][j]>>h[i][j];

        }

        dp[1][1][l-1]=h[1][1],dp[1][2][l-1]=h[1][2],dp[1][3][l-1]=h[1][3];
        for(int i=2;i<=n;i++)
        {

            for(int j=1;j<=3;j++)
            {
                dp[i][j]=dp[i-1][j];
                if(j==1)
                {
                    for(int w=1;w<=a;w++)
                    {
                        //if(w>1)
                        dp[i][1][w]=max(dp[i-1][1][w-1]+h[i][j],dp[i][j]);
                    }


                }

            }
        }
                //for(int k=0;k<=l;k++)
                //{

                    /*dp[i][j][k]=dp[i-1][i][k];
                    if(j==1||a!=0)
                    {
                        dp[i][1][k]=max(dp[i-1][1][k-1]+h1[i],dp[i][1][k]);
                        if(dp[i][1][k]==dp[i-1][1][k-1]+h1[i])
                            a--;
                    }

                    else if(j==2||b!=0)
                    {
                        dp[i][2][k]=max(dp[i-1][2][k-1]+h2[i],dp[i][2][k]);
                        if(dp[i][2][k]==dp[i-1][2][k-1]+h2[i])
                            b--;
                    }
                    else if(j==3||c!=0)
                    {
                        dp[i][3][k]=max(dp[i-1][3][k-1]+h3[i],dp[i][3][k]);
                        if(dp[i][3][k]==dp[i-1][3][k-1]+h3[i])
                                c--;
                    }* /


                //}


    //cout<<dp[n][1][l]<<" "<<dp[n][2][l]<<" "<<dp[n][3][l]<<endl;
    //}

    return 0;
}*/
