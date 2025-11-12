#include<bits/stdc++.h>
using namespace std;
struct node
{
    int a1,a2,a3;

}x[100005];
struct no
{
    int id,val,be;
}qw[200005];
int n;
int maxn;
void dfs(int step,int ans,int a,int b)
{
    if(step>n)
    {
        maxn=max(maxn,ans);
        return;
    }
    if(a<n/2)
        dfs(step+1,ans+x[step].a1,a+1,b);
    if(b<n/2)
        dfs(step+1,ans+x[step].a2,a,b+1);
    if((step-a-b)<n/2)
        dfs(step+1,ans+x[step].a3,a,b);

}
bool cmp1(node q,node w)
{
    if(q.a1==w.a1)
    {
        return q.a2>w.a2;
    }
    return q.a1>w.a1;
}
bool cmp2(no q,no w)
{
    return q.val>w.val;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        maxn=-1;
        bool f1=true;
        bool f2=true;
        bool f3=true;
        for(int i=1;i<=n;i++)
        {
            cin>>x[i].a1>>x[i].a2>>x[i].a3;
            f1=(f1&&(!x[i].a1));
            f2=(f2&&(!x[i].a2));
            f3=(f3&&(!x[i].a3));
        }
        if(n<=10)
        {
            dfs(0,0,0,0);
        }
        else if(f2&&f3)
        {
            sort(x+1,x+n+1,cmp1);
            maxn=0;
            for(int i=1;i<=n/2;i++)
            {
                maxn+=x[i].a1;
            }

        }
        else if(f3)
        {
            //cout<<"---------------------------------------"<<endl;
            for(int i=1;i<=n;i++)
            {
                qw[2*i-1].val=x[i].a1;
                qw[2*i].val=x[i].a2;
                qw[2*i-1].be=1;
                qw[2*i].be=2;
                qw[2*i-1].id=i;
                qw[2*i].id=i;
            }
            sort(qw+1,qw+2*n+1,cmp2);
            maxn=0;
            vector<bool> vis(n+1,false);
            int cnt1=0;
            int cnt2=0;
            for(int i=1;i<=2*n;i++)
            {
                if(vis[qw[i].id])
                {
                    continue;
                }
                if(qw[i].be==1)
                {
                    if(cnt1<n/2){
                        maxn+=qw[i].val;
                        vis[qw[i].id]=1;
                        cnt1++;
                    }
                }
                else
                {
                    if(cnt2<n/2)
                    {
                        maxn+=qw[i].val;
                        vis[qw[i].id]=1;
                        cnt2++;
                    }
                }
            }
        }
        else
        {
            dfs(0,0,0,0);
        }
        cout<<maxn<<endl;
    }
    return 0;
}
