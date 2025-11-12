#include <bits/stdc++.h>
using namespace std;
const int DATA=20;
/*
char vis[DATA]={};
dfs()
{
    if()
    {
    }
    else
    {
        vis[i]=1;
        dfs()
        vis[i]=0;
    }
    return;
}
*/
/*
struct xxx{

};
xxx ecm[DATA]={};
*/
/*
xx P()
{
    return xx;
}
*/
int inputs[DATA]={};
int bitter(int n)
{
    int result=0;
    for(int i=31;i>=0;i--)
    {
        if((1<<i)&n)
        {
            result++;
        }
    }
    return result;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int result=0;
    int n=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&inputs[i]);
    }
    for(int j=0;j<(1<<n);j++)
    {
        if(bitter(j)>=3)
        {
            int acm=0,maxs=INT_MIN;
            for(int k=0;k<n;k++)
            {
                if((1<<k)&j)
                {
                    acm+=inputs[k];
                    maxs=max(inputs[k],maxs);
                }
            }
            if(acm>2*maxs)
            {
                result++;
            }
        }
    }
    cout<<result;
    return 0;
}