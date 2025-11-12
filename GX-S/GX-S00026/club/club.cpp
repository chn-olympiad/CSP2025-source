#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int T;
int n;
int cnt[4];
struct node
{
  int big,mid,sma;
  int val[4];//1 is the biggest,2 is the middle and 3 is the smallest
}f[N];
struct fina
{
  int val,id,ran;
  bool operator <(const fina &x)const
  {
    return val>x.val;
  }
};
struct r
{
  int id;
  int val;
};
bool cmp1(r x1,r x2)
{
  return x1.val>x2.val;
}
bool cmp2(node x1,node x2)
{
  if(x1.val[x1.big]==x2.val[x2.big])
  {
    if(x1.val[x1.mid]==x2.val[x2.mid]) return x1.val[x1.sma]>x2.val[x2.sma];
    return x1.val[x1.mid]>x2.val[x2.mid];
  }
  return x1.val[x1.big]>x2.val[x2.big];
}
void getrank(int id,int a,int b,int c)
{
  f[id].val[1]=a,f[id].val[2]=b,f[id].val[3]=c;
  r d[4];
  d[1]=(r){1,a};
  d[2]=(r){2,b};
  d[3]=(r){3,c};
  sort(d+1,d+4,cmp1);
  if(d[1].id==1) f[id].big=1;
  if(d[1].id==2) f[id].big=2;
  if(d[1].id==3) f[id].big=3;

  if(d[2].id==1) f[id].mid=1;
  if(d[2].id==2) f[id].mid=2;
  if(d[2].id==3) f[id].mid=3;

  if(d[3].id==1) f[id].sma=1;
  if(d[3].id==2) f[id].sma=2;
  if(d[3].id==3) f[id].sma=3;
}
int main()
{
  freopen("club.in","r",stdin);
  freopen("club.out","w",stdout);
  scanf("%d",&T);
  while(T--)
  {
    int ans=0;
    scanf("%d",&n);
    memset(f,0,sizeof(f));
    memset(cnt,0,sizeof(cnt));
    for(int i=1; i<=n; i++)
    {
      int a,b,c;
      scanf("%d%d%d",&a,&b,&c);
      getrank(i,a,b,c);
    }
    sort(f+1,f+n+1,cmp2);
    priority_queue<fina>a,b,c;

    for(int i=1; i<=n; i++)
    {
      int bigg=f[i].val[f[i].big];
      if(cnt[f[i].big]+1<=n/2)
      {
        cnt[f[i].big]++;
        if(f[i].big==1) a.push((fina){bigg,i,1});
        if(f[i].big==2) b.push((fina){bigg,i,1});
        if(f[i].big==3) c.push((fina){bigg,i,1});
        ans+=bigg;
        continue;
      }
      fina now;
      if(f[i].big==1)
      {
        now=a.top();
        a.pop();
        cnt[1]--;
      }
      if(f[i].big==2)
      {
        now=b.top();
        b.pop();
        cnt[2]--;
      }
      if(f[i].big==3)
      {
        now=c.top();
        c.pop();
        cnt[3]--;
      }
      int wait;
      int flag=0;
      if(now.ran==1) wait=f[now.id].val[f[now.id].mid],flag=f[now.id].big;
      if(now.ran==2) wait=f[now.id].val[f[now.id].sma],flag=f[now.id].mid;

      if(ans+bigg-f[now.id].val[flag]+wait>=ans+f[i].val[f[i].mid])
      {
        ans=ans+bigg-f[now.id].val[flag]+wait;
        if(f[i].big==1) a.push((fina){bigg,i,1}),cnt[1]++;
        if(f[i].big==2) b.push((fina){bigg,i,1}),cnt[2]++;
        if(f[i].big==3) c.push((fina){bigg,i,1}),cnt[3]++;

        if(now.ran==1)
        {
          if(f[now.id].mid==1) a.push((fina){f[now.id].val[f[now.id].mid],now.id,2}),cnt[1]++;
          if(f[now.id].mid==2) b.push((fina){f[now.id].val[f[now.id].mid],now.id,2}),cnt[2]++;
          if(f[now.id].mid==3) c.push((fina){f[now.id].val[f[now.id].mid],now.id,2}),cnt[3]++;
        }
        if(now.ran==2)
        {
          if(f[now.id].sma==1) a.push((fina){f[now.id].val[f[now.id].sma],now.id,3}),cnt[1]++;
          if(f[now.id].sma==2) b.push((fina){f[now.id].val[f[now.id].sma],now.id,3}),cnt[2]++;
          if(f[now.id].sma==3) c.push((fina){f[now.id].val[f[now.id].sma],now.id,3}),cnt[3]++;
        }
      }
      else
      {
        if(f[i].mid==1) a.push((fina){f[i].val[f[i].mid],i,1}),cnt[1]++;
        if(f[i].mid==2) b.push((fina){f[i].val[f[i].mid],i,1}),cnt[2]++;
        if(f[i].mid==3) c.push((fina){f[i].val[f[i].mid],i,1}),cnt[3]++;

        if(now.ran==1)
        {
          if(f[now.id].big==1) a.push((fina){f[now.id].val[f[now.id].big],now.id,1}),cnt[1]++;
          if(f[now.id].big==2) b.push((fina){f[now.id].val[f[now.id].big],now.id,1}),cnt[2]++;
          if(f[now.id].big==3) c.push((fina){f[now.id].val[f[now.id].big],now.id,1}),cnt[3]++;
        }
        if(now.ran==2)
        {
          if(f[now.id].mid==1) a.push((fina){f[now.id].val[f[now.id].mid],now.id,2}),cnt[1]++;
          if(f[now.id].mid==2) b.push((fina){f[now.id].val[f[now.id].mid],now.id,2}),cnt[2]++;
          if(f[now.id].mid==3) c.push((fina){f[now.id].val[f[now.id].mid],now.id,2}),cnt[3]++;
        }
      }
    }
    printf("%d\n",ans);
  }
  return 0;
}
