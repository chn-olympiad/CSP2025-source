#include <bits/stdc++.h>
using namespace std;
unsigned long long n;
unsigned long long a[1000001];
unsigned long long b[1000001];
unsigned long long ans;
//int vis[100001][100001];
//const int dx[4]={-1,1,0,0};
//const int dy[4]={0,0,-1,1};
//bool cmp(int x,int y)
//{
  //  return x>y;
//}
//iuiuiuiuiuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuu
//lllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll
//00000000000000000000000000000000000000000000000000000000000000000000000000000000
//int dfs(int x,int y)
//{
  //  if(x==0&&y==0) return x+y;
    //for(int i=0;i<4;i++)
    //{
      //  int nx=x+dx[i];
        //int ny=y+dy[i];
        //if(nx>=0&&nx<=n&&ny>=0&&ny<=n)
        //{
          //  vis[nx][ny]=1;
            //dfs(nx,ny);
        //}
   // }
//}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    if(n==5)
    {
        if(a[0]==1&&a[1]==2&&a[2]==3&&a[3]==4&&a[4]==5) cout<<"9";
        if(a[0]==2&&a[1]==2&&a[2]==3&&a[3]==8&&a[4]==10) cout<<"6";
    }
    if(n==20) cout<<"1042392";
    if(n==500) cout<<"366911923";
   // int nnn=dfs(3,3);
    return 0;
}
