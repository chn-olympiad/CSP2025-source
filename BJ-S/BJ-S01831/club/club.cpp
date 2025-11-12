#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int wei,zhi;
    bool operator < (const Node x)const{return x.zhi<zhi;}
};

int a[100005],b[100005],c[100005];
int dp[205][205][205];
int maxshu;
int n;

priority_queue <Node> qa,qb,qc;

void dfs(int step,int shua,int shub,int shuc,int num)
{
    if (step>n)
    {
        maxshu=max(maxshu,num);
        return;
    }
    if (shua<n/2) dfs(step+1,shua+1,shub,shuc,num+a[step]);
    if (shub<n/2) dfs(step+1,shua,shub+1,shuc,num+b[step]);
    if (shuc<n/2) dfs(step+1,shua,shub,shuc+1,num+c[step]);
}

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        while (!qa.empty())
            qa.pop();
        while (!qb.empty())
            qb.pop();
        while (!qc.empty())
            qc.pop();
        cin >> n;
        for (int i=1;i<=n;i++)
            cin >> a[i] >> b[i] >> c[i];
        /*if (n<=10)
        {
            maxshu=0;
            dfs(1,0,0,0,0);
            cout << maxshu << endl;
            continue;
        }*/
        if (n<=200)
        {
            memset(dp,0,sizeof(dp));
            for (int ren=1;ren<=n;ren++)
                for (int i=0;i<=min(ren,n/2);i++)
                    for (int j=0;j<=min(ren-i,n/2);j++)
                    {
                        int k=ren-i-j;
                        if (k>n/2) continue;
                        if (i>0) dp[i][j][k]=dp[i-1][j][k]+a[ren];
                        if (j>0) dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k]+b[ren]);
                        if (k>0) dp[i][j][k]=max(dp[i][j][k],dp[i][j][k-1]+c[ren]);
                    }
            int ans=0;
            for (int i=0;i<=n/2;i++)
                for (int j=0;j<=n-i;j++)
                {
                    int k=n-i-j;
                    ans=max(ans,dp[i][j][k]);
                }
            cout << ans << endl;
            continue;
        }
        int sum=0;
        for (int i=1;i<=n;i++)
        {
            if (a[i]>=b[i] && a[i]>=c[i])
            {
                if (qa.size()<n/2)
                {
                    sum=sum+a[i];
                    Node why;
                    why.wei=i;
                    why.zhi=a[i];
                    qa.push(why);
                }
                else
                {
                    if (a[i]+b[qa.top().wei]>a[qa.top().wei]+max(b[i],c[i]))
                    {
                        sum=sum-a[qa.top().wei]+a[i]+b[qa.top().wei];
                        Node why;
                        why.wei=qa.top().wei;
                        why.zhi=b[qa.top().wei];
                        qb.push(why);
                        qa.pop();
                        why.wei=i;
                        why.zhi=a[i];
                        qa.push(why);
                    }
                    else if (a[i]+c[qa.top().wei]>a[qa.top().wei]+max(b[i],c[i]))
                    {
                        sum=sum-a[qa.top().wei]+a[i]+c[qa.top().wei];
                        Node why;
                        why.wei=qa.top().wei;
                        why.zhi=c[qa.top().wei];
                        qc.push(why);
                        qa.pop();
                        why.wei=i;
                        why.zhi=a[i];
                        qa.push(why);
                    }
                    else
                    {
                        if (a[i]>b[i])
                        {
                            sum=sum+a[i];
                            Node why;
                            why.wei=i;
                            why.zhi=a[i];
                            qa.push(why);
                        }
                        else
                        {
                            sum=sum+b[i];
                            Node why;
                            why.wei=i;
                            why.zhi=b[i];
                            qb.push(why);
                        }
                    }
                }
            }
            else if (b[i]>=a[i] && b[i]>=c[i])
            {
                if (qb.size()<n/2)
                {
                    sum=sum+b[i];
                    Node why;
                    why.wei=i;
                    why.zhi=b[i];
                    qb.push(why);
                }
                else
                {
                    if (b[i]+a[qb.top().wei]>b[qb.top().wei]+max(a[i],c[i]))
                    {
                        sum=sum-b[qb.top().wei]+b[i]+a[qb.top().wei];
                        Node why;
                        why.wei=qb.top().wei;
                        why.zhi=a[qb.top().wei];
                        qa.push(why);
                        qb.pop();
                        why.wei=i;
                        why.zhi=b[i];
                        qb.push(why);
                    }
                    else if (b[i]+c[qb.top().wei]>b[qb.top().wei]+max(a[i],c[i]))
                    {
                        sum=sum-b[qb.top().wei]+b[i]+c[qb.top().wei];
                        Node why;
                        why.wei=qb.top().wei;
                        why.zhi=c[qb.top().wei];
                        qc.push(why);
                        qb.pop();
                        why.wei=i;
                        why.zhi=b[i];
                        qb.push(why);
                    }
                    else
                    {
                        if (a[i]>c[i])
                        {
                            sum=sum+a[i];
                            Node why;
                            why.wei=i;
                            why.zhi=a[i];
                            qa.push(why);
                        }
                        else
                        {
                            sum=sum+c[i];
                            Node why;
                            why.wei=i;
                            why.zhi=c[i];
                            qc.push(why);
                        }
                    }
                }
            }
            else if (c[i]>=a[i] && c[i]>=b[i])
            {
                if (qc.size()<n/2)
                {
                    sum=sum+c[i];
                    Node why;
                    why.wei=i;
                    why.zhi=c[i];
                    qc.push(why);
                }
                else
                {
                    if (c[i]+a[qc.top().wei]>c[qc.top().wei]+max(b[i],a[i]))
                    {
                        sum=sum-c[qc.top().wei]+c[i]+a[qc.top().wei];
                        Node why;
                        why.wei=qc.top().wei;
                        why.zhi=a[qc.top().wei];
                        qa.push(why);
                        qc.pop();
                        why.wei=i;
                        why.zhi=c[i];
                        qc.push(why);
                    }
                    else if (a[i]+c[qc.top().wei]>a[qc.top().wei]+max(b[i],a[i]))
                    {
                        sum=sum-c[qc.top().wei]+c[i]+b[qc.top().wei];
                        Node why;
                        why.wei=qc.top().wei;
                        why.zhi=b[qc.top().wei];
                        qb.push(why);
                        qc.pop();
                        why.wei=i;
                        why.zhi=c[i];
                        qc.push(why);
                    }
                    else
                    {
                        if (b[i]>a[i])
                        {
                            sum=sum+b[i];
                            Node why;
                            why.wei=i;
                            why.zhi=b[i];
                            qb.push(why);
                        }
                        else
                        {
                            sum=sum+a[i];
                            Node why;
                            why.wei=i;
                            why.zhi=a[i];
                            qa.push(why);
                        }
                    }
                }
            }
            //cout << "&&&" << sum << endl;
        }
        cout << sum << endl;
    }

    return 0;
}
