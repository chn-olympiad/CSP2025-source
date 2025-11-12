#include<bits/stdc++.h>
using namespace std;
int t;
int n;
bool f=1,p=1;
int a1[100005];
int a2[100005];
int a3[100005];
int ans=0;
priority_queue<int,vector<int>,greater<int> > q1,q2;
void dfs(int step,int n1,int n2,int n3,int sum)
{
    if(n1>n/2||n2>n/2||n3>n/2)return;
    if(step==n+1)
    {
        ans=max(ans,sum);
        return;
    }
    dfs(step+1,n1+1,n2,n3,sum+a1[step]);
    dfs(step+1,n1,n2+1,n3,sum+a2[step]);
    dfs(step+1,n1,n2,n3+1,sum+a3[step]);
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        f=1;
        p=1;
        while(!q1.empty())q1.pop();
        while(!q2.empty())q2.pop();
        ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d%d%d",&a1[i],&a2[i],&a3[i]);
        for(int i=1;i<=n;i++)
        {
            if(a2[i]!=0||a3[i]!=0)
            f=0;
        }
        if(f==1)
        {
            sort(a1+1,a1+n+1);
            for(int i=n;i>=n/2+1;i--)ans+=a1[i];
            printf("%d\n",ans);
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            if(a3[i]!=0)
            p=0;
        }
        if(p==1)
        {
            for(int i=1;i<=n;i++)
            {
                if(a1[i]>=a2[i])q1.push(a1[i]-a2[i]),ans+=a1[i];
                else q2.push(a2[i]-a1[i]),ans+=a2[i];
            }
            while(q1.size()>n/2)
            {
                ans-=q1.top();
                q1.pop();
            }
            while(q2.size()>n/2)
            {
                ans-=q2.top();
                q2.pop();
            }
            printf("%d\n",ans);
            continue;
        }
        dfs(1,0,0,0,0);
        printf("%d\n",ans);
    }
    return 0;
}
