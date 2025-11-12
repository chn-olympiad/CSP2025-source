#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][5],ans[7],ant=0,anss=0;
int memb[5];
struct node{
    int c;
    int a0;
};
node pref[100005][5];
void tran(int p)
{
    bool b[3];
    for(int f=1;f<=3;f++)
    {
        if(b[1]==0)
        {
            if(a[p][f]==max(a[p][1],a[p][2],a[p][3]))
            {
                pref[p][1].a0=a[p][f];
                b[1]=1;
                pref[p][1].c=f;
                continue;
            }
        }
        if(b[2]==0)
        {
            if(a[p][f]==min(a[p][1],a[p][2],a[p][3]))
            {
                pref[p][3].a0=a[p][f];
                b[2]=1;
                pref[p][3].c=f;
                continue;
            }
        }
        pref[p][2].a0=a[p][f];
        pref[p][2].c=f;
    }
}
void dfs(int p)
{
    if(memb[1]>n/2||memb[2]>n/2||memb[3]>n/2)   return;
    if(p==n+1)    {anss=max(ant,anss);    return;}
    for(int j=1;j<=3;j++)
    {
        ant+=pref[p][j].a0;
        memb[pref[p][j].c]++;
        dfs(p+1);
        ant-=pref[p][j].a0;
        memb[pref[p][j].c]--;
    }
}
void clear()
{
    anss=0;  ant=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=3;j++)   a[i][j]=0;
}
int main()
{
    scanf("%d",&t);
    for(int h=1;h<=t;h++)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=3;j++)     scanf("%d",&a[i][j]);
            tran(i);
        }
        dfs(1);
        ans[h]=anss;
        clear();
    }
    for(int h=1;h<=t;h++)  printf("%d\n",ans[h]);
    return 0;
}
