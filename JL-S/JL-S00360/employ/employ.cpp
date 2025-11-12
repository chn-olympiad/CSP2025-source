#include<bits/stdc++.h>
using namespace std;
char s[1100];
int c[1100],flag[1100];
int ans=0,n,m;
void dfs(int x,int num,int k)
{
    if(x>n&&num>=m)
    {
        ans++;
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(flag[i]==0)
        {
            flag[i]=1;
            if(k>=c[i]||s[x]=='0')
            {
                dfs(x+1,num,k+1);
            }
            else
            {
                dfs(x+1,num+1,k);
            }
            flag[i]=0;
        }
    }
}
int main()
{
    //freopen("employ.in","r",stdin);
    //freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&c[i]);
    }
    dfs(1,0,0);
    printf("%d\n",ans);
    return 0;
}
