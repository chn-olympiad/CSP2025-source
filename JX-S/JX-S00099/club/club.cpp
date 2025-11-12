#include<bits/stdc++.h>
using namespace std;
int c,b[1000],a[1000005][10],n,p,k,t,maxx;
//long long 0000];
int dfs(int x,int y)
{
if(x==n+1)
{
   maxx=max(maxx,y);
   }
for(int i=1;i<=3;i++)
{
if(b[i]<n/2)
{
   b[i]++;
   dfs(x+1,y+a[x][i]);
   b[i]--;
   }
}return 0;
}   
int main()
{
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);

cin>>t;
while(k<t)
{
cin>>n;maxx=0;
for(int i=1;i<=n;i++)
for(int j=1;j<=3;j++)
cin>>a[i][j];
dfs(1,0);
cout<<maxx<<endl;
//cout<<endl<<"woshinvsheng"<<endl;
k++;c=0;
}
}
