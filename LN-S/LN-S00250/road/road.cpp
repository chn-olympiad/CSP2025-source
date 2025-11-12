#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e6+5;
int fa[N],n,m,q,c[15][N],r1,r2,cnt,h,x;
long long num;
struct mz
{
    int u,v,w;
}a[M];
map<pair<int,int>,int> mp; 
mz stk[M];
bool cmp(mz a,mz b)
{
    return a.w<b.w;
}
int find(int root)
{
    if(fa[root]==root) return root;
    else return fa[root]=find(fa[root]);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout); 
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i].u>>a[i].v>>a[i].w;
    }
    for(int i=1;i<=q;i++)
    {
        for(int j=0;j<=m;j++)
        {
            cin>>c[i][j];
        }
    }
    sort(a+1,a+1+m,cmp);
    for(int i=1;i<=m;i++)
    {
        r1=find(a[i].u);
        r2=find(a[i].v);
        if(r1==r2) continue;
        fa[r1]=r2;
        num+=a[i].w;
        stk[++cnt]=a[i];       
    }
    // cout<<num<<'\n';
    if(q==0)
    {
        cout<<num;
        return 0;
    }
    for(int i=1;i<=q;i++)
    {
        mp.clear();
        if(c[i][0]>num) continue;
        bool flag=0;
        int num1=0;
        for(int j=cnt;j>=1;j--)
        {
            if(c[i][stk[j].u]>c[i][stk[j].v])
            {
                x=stk[j].v;
            }
            else x=stk[j].u;
            if(flag) num1=c[i][x];
            else num1=c[i][0]+c[i][x];
            if(num1>stk[j].w) continue;
            int mn=INT_MAX;
            int p=0;
            for(int k=1;k<=n;k++)
            {
                if(k!=x)
                if(mn>c[i][k])
                {
                    mn=c[i][k];
                    p=k;
                }
            }
            // cout<<mp[{stk[j].u,x}]<<" "<<mp[{x,stk[j].u}]<<" "<<mp[{stk[j].v,x}]<<" "<<mp[{x,stk[j].v}]<<'\n';
            if(mp[{stk[j].v,p}]||mp[{stk[j].u,p}]) continue;
            if(stk[j].w>num1+mn)
            {
                flag=1;
    //    cout<<stk[j].w<<" "<<num1<<" "<<mn<<" ";
                num-=stk[j].w;
                stk[j].w=num1+mn;
                num+=stk[j].w;
                // cout<<stk[j].u<<" "<<stk[j].v<<" "<<p<<" "<<stk[j].w<<" "<<num<<'\n';
                mp[{stk[j].u,p}]=1;mp[{p,stk[j].u}]=1;mp[{stk[j].v,p}]=1;mp[{p,stk[j].v}]=1;
                // cout<<mp[{stk[j].u,x}]<<" "<<mp[{x,stk[j].u}]<<" "<<mp[{stk[j].v,x}]<<" "<<mp[{x,stk[j].v}]<<'\n';
            }
        }
    }
    cout<<num;
    return 0;
}