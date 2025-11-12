#include<bits/stdc++.h>
using namespace std;
struct road
{
    int u,v,w;
}a[1000050];
bool cmp(road e,road f)
{
    return e.u<f.u;
}
int n,m,k;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int ci,aij,t,k,mine,sum;
    cin>>n>>m>>k;
    for(int i=0;i<m;i++)
    {
        cin>>a[i].u>>a[i].v>>a[i].w;
    }
    for(int i=0;i<k;i++)
    {
        cin>>ci>>aij;
    }
    sort(a,a+m,cmp);
    t=0;
    for(int i=0;i<n;i++)
    {
        mine=2000000000;
        for(int j=i+1;j<n;j++)
        {
            for(k=t;k<m;k++)
            {
                if(a[k].u==i&&a[k].v==j)
                {
                    mine=min(mine,a[k].w);
                }
                else if(a[k].u>i)
                {
                    break;
                }
            }
        }
        t=k;
        sum+=mine;
    }
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
