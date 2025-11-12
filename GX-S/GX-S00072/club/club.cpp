#include<bits/stdc++.h>
using namespace std;
int const N=1e5+1;
int n,a[4][N],shu[N],da[N][4];
int bp[N];
struct node
{
    int a,b;
    void ab(int x,int y)
    {
        a=x;
        b=y;
    }
};
struct st{
    bool operator()(node x,node y)
    {
        return x.a>y.a;
    }
};
void num()
{
    int sum=0;
    int s[4]={0,0,0,0};
    priority_queue<node,vector<node>,st > si[4];
    for(int k=1;k<=2;k++)
    {
        for(int i=1;i<=n;i++)
        {
            if(bp[i]==1) continue;
            if(s[da[i][k]]==n/2){
                node t=si[da[i][k]].top();
                if(t.a<a[da[i][k]][i]-a[da[i][k+1]][i])
                {
                    si[da[i][k]].pop();
                    sum+=a[da[i][k]][i];
                    sum=sum-a[da[i][k]][t.b];
                    t.a=a[da[i][k]][i]-a[da[i][k+1]][i];
                    bp[t.b]=0;
                    t.b=i;
                    si[da[i][k]].push(t);
                    bp[i]=1;
                }
            }
            else{
                s[da[i][k]]++;
                sum+=a[da[i][k]][i];
                node tk;
                tk.a=a[da[i][k]][i]-a[da[i][k+1]][i];
                tk.b=i;
                si[da[i][k]].push(tk);
                bp[i]=1;
            }
        }
    }
    cout<<sum;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        memset(bp,0,sizeof(bp));
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d",&a[1][i],&a[2][i],&a[3][i]);
            if(a[1][i]>=a[2][i]&&a[1][i]>=a[3][i])
            {
                da[i][1]=1;
                if(a[2][i]>=a[3][i])
                {
                    da[i][2]=2;
                    da[i][3]=3;
                }
                else
                {
                    da[i][2]=3;
                    da[i][3]=2;
                }
                continue;
            }
            else
            {
                if(a[2][i]>=a[3][i]&&a[2][i]>=a[1][i])
                {
                    da[i][1]=2;
                    if(a[1][i]>=a[3][i])
                    {
                        da[i][2]=1;
                        da[i][3]=3;
                    }
                    else
                    {
                        da[i][2]=3;
                        da[i][3]=1;
                    }
                    continue;
                }
                else
                {
                    da[i][1]=3;
                    if(a[1][i]>=a[2][i])
                    {
                        da[i][2]=1;
                        da[i][3]=2;
                    }
                    else
                    {
                        da[i][2]=2;
                        da[i][3]=1;
                    }
                }
            }
        }
        num();
    }
    return 0;
}
