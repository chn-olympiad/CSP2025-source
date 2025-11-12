//#include<bits/stdc++.h>
//using namespace std;

//const int maxm=2*1e6+5;
//const int maxn=1e4+5;
//const int maxa=1e9+5;

//int n,m,k;
//long long ans=0;
//int dp[305][305][305];
//int vis[maxn+15];

//struct node
//{
//    int to,w;
//};

//vector<node> e1[maxm];
//vector<int> left;

//void addedge(int u,int v,int w)
//{
//    e1[u].push_back({v,w});
//}

//void dfs(int x,int fa)
//{
//    int minn=maxa;
//    int minnp=0;
//    for(auto i:e1[x])
//    {
//        if(i.to==fa)continue;
//        if(i.w<minn)
//        {
//            minn=i.w,minnp=i.to;
//        }
//    }
//    vis[minnp]=1;
//    w+=minn;
//    dfs(minnp,x);
//}

//void solve1()
//{

//    dfs(1,0);
    //for(int i=1;i<=n;i++)
   // {
  //      for(int j=1;j<=n;j++)
//        {
            //for(int t=1;t<=j;t++)
          //  {
        //        dp[i][j]=min(dp[i][j],dp[i][t]+dp[i][j-t]);
      //      }
    //    }
  //  }
//}

//void init()
//{
    //memset(vis,0,sizeof(vis));
    //cfr=0;
 //   cin>>n>>m>>k;
 //   for(int i=1;i<=300;i++)
   // {
  //      for(int j=1;j<=300;j++)
    //    {
       //     dp[i][j]=maxa+5;
         //   if(i==j)dp[i][j]=0;
     //   }
   // }
  //  for(int i=1;i<=m;i++)
  //  {
     //   int u,v,w;
   //     cin>>u>>v>>w;
    //    dp[u][v]=w;
      //  dp[v][u]=w;
        //addedge(u,v,w);
        //addedge(v,u,w);

  //  }
    //for(int i=1;i<=n;i++)
    //{
    //    left.push_back(i);
    //}
   // if(n<=300)
 //   solve1();
//    cout<<ans;
//}

int main()
{
   // init();
    //solve();
    return 0;
}

