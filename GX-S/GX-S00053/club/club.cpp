#include<bits/stdc++.h>
using namespace std;
struct ed
{
    int a1,a2,a3;
    int ch;
    int ma,mid;
}e[100010];
bool cmp(ed x,ed y)
{
    return x.a1>y.a1;
}
struct ev
{
    int num,sum,wh;
}k[300030];
bool cmp2(ev x,ev y)
{
    return x.sum>y.sum;
}
struct node
{
    int cha,numb;
    bool operator < (const node&a)    const{return cha>a.cha;}
};
int color[100010];
priority_queue<node> q[5];
int T;
long long ans;
int n;
void dfs(int maxx,int a,int b,int c,int i,long long aans,long long bans,long long cans)
{
    if(a>maxx||b>maxx||c>maxx)  return ;
    if(i==n+1)  {ans=max(ans,(aans+bans+cans));return ;}
    dfs(maxx,a+1,b,c,i+1,aans+e[i].a1,bans,cans);
    dfs(maxx,a,b+1,c,i+1,aans,bans+e[i].a2,cans);
    dfs(maxx,a,b,c+1,i+1,aans,bans,cans+e[i].a3);
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    for(int u=1;u<=T;u++)
    {
        n=0;
        cin>>n;
        int A=0;
        for(int i=1;i<=n;i++)
        {
            cin>>e[i].a1>>e[i].a2>>e[i].a3;
            if(e[i].a2!=0||e[i].a3!=0)  A=1;
        }
        if(A==0)
        {
            sort(e+1,e+n+1,cmp);
            for(int i=1;i<=n/2;i++)
                ans+=e[i].a1;
            cout<<ans<<endl;
        }
        else    if(n<=10)
        {
            dfs(n/2,0,0,0,1,0,0,0);
            cout<<ans<<endl;
        }
        else
        {
            int tot=0;
            for(int i=1;i<=n;i++)
            {
                k[++tot].sum=e[i].a1;k[tot].num=i;k[tot].wh=1;
                k[++tot].sum=e[i].a2;k[tot].num=i;k[tot].wh=2;
                k[++tot].sum=e[i].a3;k[tot].num=i;k[tot].wh=3;
                if(e[i].a1>=e[i].a2&&e[i].a1>=e[i].a3)
                {
                    e[i].ma=1;
                    if(e[i].a2>=e[i].a3)    {e[i].mid=2;e[i].ch=e[i].a1-e[i].a2;}
                    else    {e[i].mid=3;e[i].ch=e[i].a1-e[i].a3;}
                }
                else    if(e[i].a2>=e[i].a1&&e[i].a2>=e[i].a3)
                {
                    e[i].ma=2;
                    if(e[i].a1>=e[i].a3)    {e[i].mid=1;e[i].ch=e[i].a2-e[i].a1;}
                    else    {e[i].mid=3;e[i].ch=e[i].a2-e[i].a3;}
                }
                else    if(e[i].a3>=e[i].a1&&e[i].a3>=e[i].a2)
                        {
                            e[i].ma=3;
                            if(e[i].a1>=e[i].a2)    {e[i].mid=1;e[i].ch=e[i].a3-e[i].a1;}
                            else    {e[i].mid=2;e[i].ch=e[i].a3-e[i].a2;}
                        }
            }
            sort(k+1,k+tot+1,cmp2);
            int cnt=0;
            for(int i=1;i<=tot;i++)
            {
                int v=k[i].num;
                if(color[v]==1) continue;
                color[v]=1;
                int which=k[i].wh;
                ans+=k[i].sum;
                node t;t.numb=v;t.cha=e[v].ch;
                if(q[which].size()<n/2)
                {
                    q[which].push(t);
                    continue;
                }
                else
                {
                    int nowcha=q[which].top().cha,nowv=q[which].top().numb;
                    if(nowcha<e[v].ch)
                    {
                        ans-=nowcha;
                        q[which].pop();
                        node ls;
                        ls.numb=nowv;ls.cha=e[v].ch;
                        q[e[nowv].mid].push(ls);
                        q[which].push(t);
                    }
                    else
                    {
                        ans-=e[v].ch;
                        q[e[v].mid].push(t);
                    }
                }
            }
            cout<<ans<<endl;
            while(!q[1].empty())    q[1].pop();
            while(!q[2].empty())    q[2].pop();
            while(!q[3].empty())    q[3].pop();
            for(int i=1;i<=tot;i++) k[i].num=k[i].sum=k[i].wh=0;
            for(int i=1;i<=n;i++)   color[i]=0;
        }
        for(int i=1;i<=n;i++)   e[i].a1=e[i].a2=e[i].a3=e[i].ma=e[i].ch=e[i].mid=0;
        ans=0;
    }
    return 0;
}
