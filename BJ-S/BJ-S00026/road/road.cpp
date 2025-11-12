#include<bits/stdc++.h>
using namespace std;
long long n,m,k,c[21] [10011],sum=0;
bool bol[10011];
struct A
{
    long long v,w;
};
vector<A> u[10011];
bool cmp(A a,A b)
{
    return (a.w<b.w);
}
void bfs(long long x)
{
    bol[x]=1;
    queue<long long> q;
    q.push(x);
    while(!q.empty())
    {
        long long x=q.front();
        q.pop();
        long long mn=(1<<31)-1,l=0;
        sort(u[x].begin(),u[x].end(),cmp);
        for(long long i=0;i<u[x].size();i++)
        {
            if(!bol[u[x] [i].v])
            {
                //cout<<u[x] [i].v<<' '<<x<<' '<<u[x] [i].w<<endl;
                sum+=u[x] [i].w;
                q.push(u[x] [i].v);
                bol[u[x] [i].v]=1;
            }
        }
    }

}
int main()
{

    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(long long i=1;i<=m;i++)
    {
        int t1,t2,t3;
        cin>>t1>>t2>>t3;
        u[t1].push_back({t2,t3});
        u[t2].push_back({t1,t3});
    }
    for(long long i=1;i<=k;i++)
    {
        for(long long j=0;j<=n;j++)
        {
            cin>>c[i] [j];
        }
    }
    bfs(1);
    cout<<sum;
    return 0;
}
