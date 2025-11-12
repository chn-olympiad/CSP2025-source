#include <bits/stdc++.h>
#define N 100005

using namespace std;

struct node
{
    int x,y,z;
}a[N];
struct edge
{
    int x,id;
};
int t,n,ans;
bool cmp1(node x,node y){return x.x>y.x;}
bool cmp2(node x,node y){return abs(x.x-x.y)>abs(y.x-y.y);}
queue<edge>q[2];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i].x>>a[i].y>>a[i].z;
        if(a[1].y==a[1].z&&a[1].y==0)
        {
            sort(a+1,a+n+1,cmp1);
            for(int i=1;i<=n/2;i++)
                ans+=a[i].x;
            cout<<ans<<'\n';
        }
        else if(a[1].z==0)
        {
            sort(a+1,a+n+1,cmp2);
            for(int i=1;i<=n/2;i++)
                if(a[i].x>a[i].y)
                    q[1].push((edge){a[i].x,i});
                else
                    q[2].push((edge){a[i].y,i});
            while(q[1].size()>=q[2].size())
            {
                int x=q[1].front().id;
                q[2].push((edge){a[x].y,x});
                q[1].pop();
            }
            while(q[1].size()<=q[2].size())
            {
                int x=q[2].front().id;
                q[1].push((edge){a[x].x,x});
                q[2].pop();
            }
            while(!q[1].empty())
            {
                ans+=q[1].front().x;
                q[1].pop();
            }
            while(!q[2].empty())
            {
                ans+=q[2].front().x;
                q[2].pop();
            }
            cout<<ans<<'\n';
        }
        else if(n==2)
            cout<<max(max(max(a[1].x+a[2].y,a[1].x+a[2].z),max(a[2].x+a[1].y,a[2].x+a[3].y)),max(a[3].x+a[1].y,a[3].x+a[2].y))<<'\n';
    }
    return 0;
}
