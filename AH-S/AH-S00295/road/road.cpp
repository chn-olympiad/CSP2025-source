#include<bits/stdc++.h>
using namespace std;

struct EDGE
{
    int u,v,w;
};

int n,m,k;
int fa[101210];
EDGE ed[1000510],edc[210000],join[210000];
int cst[210],cnt=0,cntc=0,cntj=0,F=1,F1,s,tmp1=0,mn = 0x3f3f3f3f;
long long sum = 0;

bool cmp(EDGE x,EDGE y)
{
    return x.w < y.w;
}

int find(int x)
{
    if(fa[x] == x) return x;
    return (fa[x]=find(fa[x]));
}

void kruskal()
{
    for(int i = 1;i <= cnt;i++)
    {
        int to = ed[i].v,st = ed[i].u;
        if(find(fa[st]) == find(fa[to]))
        {
            continue;
        }
        else
        {
         //   dis[to] = min(dis[st]+ed[i].w);
            sum += ed[i].w;
            fa[find(to)] = find(fa[st]);
        }
    }
}

void kruskal1()
{
    int j = 1;long long sum1=0;
    for(int i = 1;i <= cnt||j<=cntj;)
    {
        int to,st,wei;
        if(ed[i].w > join[j].w || i > cnt)
        {
            to = join[j].v,st = join[j].u,wei = join[j].w;
            j++;
        }
        if(ed[i].w <= join[j].w && i <= cnt)
        {
            to = ed[i].v,st = ed[i].u,wei = ed[i].w;
            i++;
        }
        if(find(fa[st]) == find(fa[to]))
        {
            continue;
        }
        else if(find(fa[st]) != find(fa[to]))
        {
         //   dis[to] = min(dis[st]+ed[i].w);
            sum1 += wei;
            fa[find(to)] = find(fa[st]);
        }
    }
  //  cout<<sum1<<endl;
    if(sum == 0) sum = sum1+tmp1;
    sum = min(sum,sum1+tmp1);
}

void init()
{
    for(int i = 1;i <= 100220;i++)
    {
        fa[i]=i;
    }
}

int main()
{

    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    init();

    cin>>n>>m>>k;

    int u,v,w;
    for(int i = 1;i <= m;i++)
    {
        cin>>u>>v>>w;
        ed[++cnt] = {u,v,w};
    }

    for(int i = 1;i <= k;i++)
    {
        cin>>cst[i];
        mn = min(mn,cst[i]);
        if(cst[i] != 0) F = 0;
        for(int i = 1;i <= n;i++)
        {
            cin>>w;
            if(w != 0) F = 0,F1 = 0;
            edc[++cntc] = {m+i,i,w};
        }
    }
    if(F)
    {
        for(int i = 1;i <= cntc;i++)
        {
            ed[++cnt] = edc[i];
        }
        sort(ed+1,ed+cnt+1,cmp);
        s = ed[1].u;
        kruskal();
       /* for(int i = 1;i <= n;i++)
        {
            sum += dis[i];
        }*/
        if(k != 0)
        {
            cout<<0;
        }
        else cout<<sum;
    }
    else
    {
        if(F1)
        {
            cout<<mn;
            return 0;
        }
        sort(ed+1,ed+cnt+1,cmp);
        for(int i = 0;i < (1<<k);i++)
        {
            tmp1=0;
            init();
            cntj = 0;
            memset(join,0,sizeof(join));
            for(int mask = 1;mask <= k;mask++)
            {
                if((i&(1 << (mask-1))) != 0)
                {
                    for(int l = 1+n*(mask-1);l <= n*mask;l++)
                    {
                        join[++cntj] = edc[l];
                    }
                    tmp1 += cst[mask];
                }
                //cout<<i<<" "<<mask-1<<" "<<tmp1<<" "<<(i&(1 << (mask-1)))<<"\n";
            }
          //  cout<<tmp1<<endl;
            sort(join+1,join+1+cntj,cmp);
            kruskal1();
        }
        cout<<sum;
    }


    return 0;
}
