#include<stdio.h>
#include<algorithm>
using namespace std;
#define ll long long  
struct node
{
    ll a,b,c,d;
};
node s[100005];
int n;
int dfs(int i,int c1,int c2,int c3)
{
    ll ans=0;
    if(i==n+1) return 0;
    if(c1<n/2) ans=max(ans,dfs(i+1,c1+1,c2,c3)+s[i].a);
    if(c2<n/2) ans=max(ans,dfs(i+1,c1,c2+1,c3)+s[i].b);
    if(c3<n/2) ans=max(ans,dfs(i+1,c1,c2,c3+1)+s[i].c);
    return ans;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%ld%ld%ld",&s[i].a,&s[i].b,&s[i].c);
        }
        printf("%ld\n",dfs(1,0,0,0));
    }
    return 0;
}
