//暴力  
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int maxn = 1e5+5;
int t;
int n;
// int a[maxn];  //对部门1满意度
// int b[maxn];  //对部门2满意度
// int c[maxn];  //对部门3满意度
struct node{
    int a;
    int b;
    int c;
}q[maxn];
int tong[maxn];
int vis[maxn];
ll sum=-1;
int ceil()  //计算每一种子集的得分
{
    ll m=0;
    for (int i=1;i<=n;i++)
    {
        if (tong[i] == 1)
            m+=q[i].a;
        if (tong[i] == 2)
            m+=q[i].b;
        if (tong[i] == 3)
            m+=q[i].c;
    }
    return m;
}
int ceil2()  //计算每一种子集的得分
{
    ll m=0;
    for (int i=1;i<=n;i++)
    {
        if (tong[i] == 1)
            m+=q[i].a;
        if (tong[i] == 2)
            m+=q[i].b;
    }
    return m;
}


void dfs(int dep){
    //dep:the dep people
    //01
    if (dep==n+1)
    {
        // for (int i=1;i<=n;i++)
        // {
        //     cout<<tong[i];
        // }
         ll now = ceil();
        //  cout<<" "<<now<<endl;
         sum = max(now,sum);
        // cout<<endl;
        return ;
    }
    for (int i=1;i<=3;i++)
    {
        if (vis[i]<(n/2)){
        vis[i]++;
        tong[dep] = i;
        dfs(dep+1);
        tong[dep] = 0;
        vis[i]--;
            
        }
    }
}
void dfs2(int dep){
    //dep:the dep people
    //01
    if (dep==n+1)
    {
        for (int i=1;i<=n;i++)
        {
            cout<<tong[i];
        }
         ll now = ceil2();
         cout<<" "<<now<<endl;
         sum = max(now,sum);
        cout<<endl;
        return ;
    }
    for (int i=1;i<=2;i++)
    {
        if (vis[i]<(n/2)){
        vis[i]++;
        tong[dep] = i;
        dfs(dep+1);
        tong[dep] = 0;
        vis[i]--;
            
        }
    }
}
bool cmpA(node u,node v)
{
    if (u.a>v.a) return 1;
    return 0;
}
bool cmpB(node u,node v)
{
    if (u.a>v.a) return 1;
    else {
        if (u.a==v.a) return u.b<v.b;
    }
    return 0;
}
bool cmpC(node u,node v)
{
    if (u.b>v.b) return 1;
    else {
        if (u.b==v.b) return u.a<v.a;
    }
    return 0;
}
bool checkA(node u[])
{
    for (int i=1;i<=n;i++)
    {
        if (u[i].b!=0) return 0;
    }
    return 1;
}
void work()
{
    if (n>=200)
    {
        //A:
    bool flagB=0;
    for (int i=1;i<=n;i++)
    {
        if (q[i].c!=0) flagB = 1;
    }
    if (!flagB) //B成立 然后判断A
    {
    if (checkA(q))  //A
    {
        sort(q+1,q+1+n,cmpA);
        for (int i=1;i<=(n/2);i++)
        sum+=q[i].a;
    }
    else {
        int dayu;
        int xiaoyu;
        for (int i=1;i<=n;i++)
        {
            if (q[i].a<q[i].b) xiaoyu++;
            if (q[i].a>q[i].b) dayu++;
        }
        if (dayu>xiaoyu)
        {
            sort (q+1,q+1+n,cmpB);
        for (int i=1;i<=(n/2);i++)
        sum+=q[i].a;
        for (int i=(n/2)+1;i<=n;i++)
        sum+=q[i].b;
        }
        else {
            sort (q+1,q+1+n,cmpC);
        //debug
        // for (int i=1;i<=n;i++)
        // {
        //     cout<<q[i].a<<" "<<q[i].b<<endl;
        // }
        for (int i=1;i<=(n/2);i++)
        sum+=q[i].b;
        for (int i=(n/2)+1;i<=n;i++)
        sum+=q[i].a;
        }
        // dfs2(1);
    }
    }

    }
   
   else{

    dfs(1);
   }
    cout<<sum<<endl;
}

void input()
{
    cin>>t;
    while (t--)
    {
        cin>>n;
        sum = 0;
        for (int i=1;i<=n;i++)
        {
            cin>>q[i].a>>q[i].b>>q[i].c; //input
        }
        work();

    }
}

int main ()
{
    
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    input();
    return 0;
}