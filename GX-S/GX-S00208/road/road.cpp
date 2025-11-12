# include <bits/stdc++.h>
# define MAXN 1005

using namespace std;

struct Node {int to;int w;struct Node* nxt;};
struct Head {struct Node* nxt;};
struct Head p[MAXN];
int k[10][MAXN];

void add(int a,int b,int w)
{
    struct Node* tmp = (struct Node*) malloc (sizeof(struct Node));
    tmp->to = b;
    tmp->w  = w;
    tmp->nxt = p[a].nxt;
    p[a].nxt = tmp;
    return ;
}

struct cmp{
    bool operator()(struct Node* a,struct Node* b)
    {
        return a->w > b->w;
    }
};

int dist[MAXN];
int vis[MAXN];
priority_queue<struct Node*,vector<struct Node*>,cmp> q;

void prim(int n)
{
    vis[1] = 1;
    for (struct Node* tmp=p[1].nxt;tmp!=NULL;tmp=tmp->nxt) {q.push(tmp);}
    int cnt=1;
    int now=1;
    int ans=0;
    while (cnt < n)
    {
        struct Node* tmp = q.top();
        q.pop();
        int now = tmp->to;
        if (vis[now]) continue;
        vis[now] = 1;
        cnt++;
        for (struct Node* tmp=p[now].nxt;tmp!=NULL;tmp=tmp->nxt)
        {
            int v = tmp->to;
            if (!vis[v]) q.push(tmp);
        }
        ans += tmp->w;
    }
    printf ("%d",ans);
    return ;
}
/*
7 8 0
1 2 9
1 3 8
2 3 7
2 4 6
4 6 5
4 5 4
5 6 3
6 7 2
*/
int main (void)
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    scanf ("%d %d %d",&n,&m,&k);
    for (int i=1;i<=n;i++) {p[i].nxt = NULL;dist[i] = INT_MAX;}
    for (int i=0;i<m;i++)
    {
        int a,b,w;
        scanf ("%d %d %d",&a,&b,&w);
        add(a,b,w);
        add(b,a,w);
    }

    prim(n);

    return 0;
}
