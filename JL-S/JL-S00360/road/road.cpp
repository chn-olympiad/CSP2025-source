#include<bits/stdc++.h>
using namespace std;
struct node{
    int x,num;
    friend bool operator < (node a,node b)
    {
        return a.num>b.num;
    }
};
node tmp,temp;
vector<pair<int,int> > a[11000];
int w[20],p[20][11000],flag[11000];
priority_queue<node> q;
pair<int,int> len[11000];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k,u,v,c,fl=0;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&u,&v,&c);
        a[u].push_back(make_pair(v,c));
        a[v].push_back(make_pair(u,c));
    }
    for(int i=1;i<=n;i++)
        len[i].first=0x3f3f3f3f;

    len[1]=make_pair(0,-1);
    tmp.x=1;
    tmp.num=0;
    q.push(tmp);
    while(!q.empty())
    {
        tmp=q.top();
        q.pop();
        if(len[tmp.x].first<tmp.num)
            continue;
        for(int i=0;i<a[tmp.x].size();i++)
        {
            if(len[a[tmp.x][i].first].first>len[tmp.x].first+a[tmp.x][i].second)
            {
                len[a[tmp.x][i].first].first=len[tmp.x].first+a[tmp.x][i].second;
                temp.x=a[tmp.x][i].first;
                temp.num=len[a[tmp.x][i].first].first;
                len[a[tmp.x][i].first].second=tmp.x;
            }
        }
    }
    int tmp;
    long long ans=0;
    for(int i=2;i<=n;i++)
    {
        if(flag[i]==1)
            continue;
        tmp=i;
        flag[i]=1;
        while(len[i].second!=-1)
        {
            i=len[i].second;
            flag[i]=1;
        }
        ans+=len[i].first;
    }
    printf("%lld\n",ans);
    return 0;
}
