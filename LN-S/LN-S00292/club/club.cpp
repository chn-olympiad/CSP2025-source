#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
struct ppp
{
    int a,b,c;
}; ppp d[N];
int vis[N];
bool cmp1(int k,int r)
{
    int x=min(d[k].a-d[k].b,d[k].a-d[k].c);
    int y=min(d[r].a-d[r].b,d[r].a-d[r].c);
    return x>y;
}
bool cmp2(int k,int r)
{
    int x=min(d[k].b-d[k].a,d[k].b-d[k].c);
    int y=min(d[r].b-d[r].a,d[r].b-d[r].c);
    return x>y;
}
bool cmp3(int k,int r)
{
    int x=min(d[k].c-d[k].b,d[k].c-d[k].a);
    int y=min(d[r].c-d[r].b,d[r].c-d[r].a);
    return x>y;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
       int n,k;
       queue<int> q1,q2,q3;
       cin>>n;
       k=n/2;
       memset(vis,0,sizeof(vis));
       for(int i=1;i<=n;i++)
       {
           cin>>d[i].a>>d[i].b>>d[i].c;
       }
       int maxn=0;
       for(int i=1;i<=n;i++)
       {
           int u=max(d[i].a,max(d[i].b,d[i].c));
           if(d[i].a==u) q1.push(i);
           else if(d[i].b==u) q2.push(i);
           else if(d[i].c==u) q3.push(i);
       }
       int fa=q1.size(),fb=q2.size(),fct=q3.size();
       if(fa>k)
       {
          int ra=q1.size();
          for(int i=1;i<=ra;i++)
          {
              vis[i]=q1.front();
              q1.pop();
          }
          sort(vis+1,vis+ra+1,cmp1);
          for(int i=1;i<=k;i++)
          {
              maxn+=d[vis[i]].a;
          }
          for(int i=k+1;i<=ra;i++)
          {
             if(d[vis[i]].a-d[vis[i]].b<=d[vis[i]].a-d[vis[i]].c) q2.push(vis[i]);
             else q3.push(vis[i]);
          }
          int rb=q2.size();
          for(int i=1;i<=rb;i++)
          {
              maxn+=d[q2.front()].b;
              q2.pop();
          }
          int rc=q3.size();
          for(int i=1;i<=rc;i++)
          {
              maxn+=d[q3.front()].c;
              q3.pop();
          }
          cout<<maxn;
       }
       if(fb>k)
       {
          int rb=q2.size();
          for(int i=1;i<=rb;i++)
          {
              vis[i]=q2.front();
              q2.pop();
          }
          sort(vis+1,vis+rb+1,cmp2);
          for(int i=1;i<=k;i++)
          {
              maxn+=d[vis[i]].b;
          }
          for(int i=k+1;i<=rb;i++)
          {
             if(d[vis[i]].b-d[vis[i]].a<=d[vis[i]].b-d[vis[i]].c) q1.push(vis[i]);
             else q3.push(vis[i]);
          }
          int ra=q1.size();
          for(int i=1;i<=ra;i++)
          {
              maxn+=d[q1.front()].a;
              //cout<<q2.front()<<endl;
              q2.pop();
          }
          int rc=q3.size();
          for(int i=1;i<=rc;i++)
          {
              maxn+=d[q3.front()].c;
              q3.pop();
          }
          cout<<maxn;
       }
       if(fct>k)
       {
          int rc=q3.size();
          for(int i=1;i<=rc;i++)
          {
              vis[i]=q3.front();
              q3.pop();
          }
          sort(vis+1,vis+rc+1,cmp3);
          for(int i=1;i<=k;i++)
          {
              maxn+=d[vis[i]].c;
          }
          for(int i=k+1;i<=rc;i++)
          {
             if(d[vis[i]].c-d[vis[i]].a<=d[vis[i]].c-d[vis[i]].b) q1.push(vis[i]);
             else q2.push(vis[i]);
          }
          int rb=q2.size();
          for(int i=1;i<=rb;i++)
          {
              maxn+=d[q2.front()].b;
              //cout<<q2.front()<<endl;
              q2.pop();
          }
          int ra=q1.size();
          for(int i=1;i<=ra;i++)
          {
              maxn+=d[q1.front()].a;
              q1.pop();
          }
          cout<<maxn;
       }
       if(fa<=k&&fb<=k&&fct<=k)
       {
          int ra=q1.size();
          for(int i=1;i<=ra;i++)
          {
              maxn+=d[q1.front()].a;
              q1.pop();
          }
          int rb=q2.size();
          for(int i=1;i<=rb;i++)
          {
              maxn+=d[q2.front()].b;
              q2.pop();
          }
          int rc=q3.size();
          for(int i=1;i<=rc;i++)
          {
              maxn+=d[q3.front()].c;
              q3.pop();
          }
          cout<<maxn;
       }
       cout<<endl;
    }
    return 0;
}
//jin li le
