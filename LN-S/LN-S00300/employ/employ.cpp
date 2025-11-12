#include<bits/stdc++.h>
using namespace std;
int n,m;
int ans;
bool flag[20];
int a[20];
int r[20];
int c[20];
string s;
void dfs(int step,int fro)
{
    if(step>n)
    {
        ans++;
    }
    for(int i=1;i<=n;i++)
    {
        if(!flag[i])
        {
            flag[i]=1;
            a[step]=i;
            dfs(step+1,0);
            flag[i]=0;
        }
    }
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
   scanf("%d%d",&n,&m);
   cin>>s;
   for(int i=1;i<=n;i++)
   {
       cin>>r[i];
   }
   dfs(1,0);
   printf("%d",ans);
   return 0;
}
