#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d[100],f[10110],ans = 1e18+7;
bool bj[10110];
struct n{
   long long x,y,z;
};
vector<n>ve;
int zhao(int ff)
{
    if(f[ff]==ff)
        return ff;
    return f[ff]=zhao(f[ff]);
}
void dfs(int di,long long sum)
{
    if(di==c)
    {
        long long amd = 0;
        for(int i = 0;i<ve.size();i++)
        {
            if(zhao(ve[i].x)!=zhao(ve[i].y)&&bj[ve[i].x]&&bj[ve[i].y])
            {
                amd+=ve[i].z;
                f[f[ve[i].x]]=f[ve[i].y];
            }
        }
        for(int i = 1;i<=a+c;i++)
            f[i]=i;
        ans=min(ans,amd+sum);
        return ;
    }
    bj[di+1+a]=true;
    dfs(di+1,sum+d[di+1]);
    bj[di+1+a]=false;
    dfs(di+1,sum);
}
bool smst(n o,n p)
{
    return o.z<p.z;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>a>>b>>c;
    for(int i = 1;i<=b;i++)
    {
        int x,y;
        cin>>x>>y;
        long long z;
        cin>>z;
        ve.push_back({x,y,z});
    }
    for(int i = 1;i<=c;i++)
    {
        cin>>d[i];
        for(int j = 1;j<=a;j++)
        {
            long long z;
            cin>>z;
            ve.push_back({i+a,j,z});
            bj[j]=true;
        }
    }
        for(int i = 1;i<=a+c;i++)
            f[i]=i;
    sort(ve.begin(),ve.end(),smst);
    dfs(0,0);
    cout <<ans;
    return 0;
}
