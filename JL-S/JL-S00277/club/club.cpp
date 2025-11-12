#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct node
{
    int x,y,z;
    friend bool operator <(node u,node v)
    {
        if(u.x!=v.x) return u.x>v.x;
        if(u.y!=v.y) return u.y>v.y;
        return u.z>=v.z;
    }
}s[N];
int T,n,choices[N];
long long ans;
void dfs(int x)
{
    if(x==n+1)
    {
        long long cnt1,sum1,cnt2,sum2,cnt3,sum3,tot;
        cnt1=cnt2=cnt3=sum1=sum2=sum3=0;
        for(int i=1;i<=n;i++)
        {
            if(choices[i]==1) cnt1++,sum1+=s[i].x;
            else if(choices[i]==2) cnt2++,sum2+=s[i].y;
            else if(choices[i]==3) cnt3++,sum3+=s[i].z;
            if(cnt1>n/2||cnt2>n/2||cnt3>n/2) return;
        }
        tot=sum1+sum2+sum3;
        ans=(tot>ans?tot:ans);
        return ;
    }
    choices[x]=1;
    dfs(x+1);
    choices[x]=2;
    dfs(x+1);
    choices[x]=3;
    dfs(x+1);
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        ans=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d %d %d",&s[i].x,&s[i].y,&s[i].z);
        }
        int flag=1;
        for(int i=1;i<=n;i++)
        {
            if(!(s[i].y==0&&s[i].z==0))
            {
                flag=0;
                break;
            }
        }
        sort(s+1,s+1+n);
        if(flag==1)
        {
            for(int i=1;i<=n/2;i++) ans+=s[i].x;
            printf("%lld\n",ans);
            continue;
        }
        dfs(1);
        printf("%lld\n",ans);
    }
    return 0;
}
