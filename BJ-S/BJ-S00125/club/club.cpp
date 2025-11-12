#include<bits/stdc++.h>
using namespace std;
struct student
{
    int a,b,c;
};
int n;
vector<student> stu;
int ans=0;
void dfs(int x,int ax,int b1,int c1,int sum)
{
    if(x==n-1)
    {
        ans=max(ans,sum);
    }
    if((ax+1)<=n/2)
    {
        dfs(x+1,ax+1,b1,c1,sum+stu[x+1].a);
    }
    if((b1+1)<=n/2)
    {
        dfs(x+1,ax,b1+1,c1,sum+stu[x+1].b);
    }
    if((c1+1)<=n/2)
    {
        dfs(x+1,ax,b1,c1+1,sum+stu[x+1].c);
    }
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
        stu.clear();
        for(int i=1;i<=n;i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            stu.push_back({a,b,c});
        }
        ans=0;
        dfs(0,1,0,0,stu[0].a);
        dfs(0,0,1,0,stu[0].b);
        dfs(0,0,0,1,stu[0].c);
        cout<<ans<<endl;
    }
    return 0;
}
