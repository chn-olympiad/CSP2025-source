#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int t,n,k;
int cnt[4]={0,0,0,0};
long long ans=0;

struct node
{
    int t[4];
    int id;
    bool vis;
}a[100005];

long long dfs(int step,int x,int y,int z)
{
    if(step>n)
    {
        return 0;
    }
    long long sum=0;
    if(x<k)
        sum=max(sum,dfs(step+1,x+1,y,z)+a[step].t[1]);
    if(y<k)
        sum=max(sum,dfs(step+1,x,y+1,z)+a[step].t[2]);
    if(z<k)
        sum=max(sum,dfs(step+1,x,y,z+1)+a[step].t[3]);

    return sum;
}

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].t[1]>>a[i].t[2]>>a[i].t[3];
        }
        k=n/2;
        cout<<dfs(1,0,0,0)<<endl;
    }


    return 0;
}
