#include<bits/stdc++.h>
using namespace std;
struct node
{
    int a[4];
}num[100010];
struct node1
{
    long long sum;
    int dis;
    int cnt[4];
};
bool cmp(node x,node y)
{
    return x.a[1]>y.a[1];
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++)
    {
        int n;
        scanf("%d",&n);
        int cnt1=0,cnt2=0;
        for(int i = 1;i<=n;i++)
        {
            for(int k = 1;k<=3;k++)
            {
                scanf("%d",&num[i].a[k]);
                if(k==2&&num[i].a[k]==0)cnt1++;
                if(k==3&&num[i].a[k]==0)cnt2++;
            }
        }
        if(cnt1==n&&cnt2==n)
        {
            sort(num+1,num+n+1,cmp);
            long long ans=0;
            for(int j = 1;j<=n/2;j++)
            {
                ans+=num[j].a[1];
            }
            printf("%lld",ans);
            continue;
        }
        int x=3;
        queue<node1>q;
        node1 f;
        long long maxn=0;
        f.dis=0,f.cnt[1]=f.cnt[2]=f.cnt[3]=0;
        f.sum=0;
        q.push(f);
        while(!q.empty())
        {
            f=q.front();
            q.pop();
            int cur=f.dis+1;
            //cout<<f.dis<<endl;
            if(cur>n)
            {
                break;
            }
            for(int k = 1;k<=x;k++)
            {
                node1 g=f;
                g.dis=cur;
                g.sum+=num[cur].a[k];
                g.cnt[k]++;
                if(g.cnt[k]>n/2)
                {
                    continue;
                }
                else
                {
                    if(g.cnt[1]+g.cnt[2]+g.cnt[3]==n)
                    {
                        maxn=max(maxn,g.sum);
                    }
                    else
                    {
                        q.push(g);
                    }
                }
            }
        }
        printf("%lld\n",maxn);
    }
    return 0;
}
