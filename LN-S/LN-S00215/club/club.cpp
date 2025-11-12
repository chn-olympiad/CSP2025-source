#include<bits/stdc++.h>
using namespace std;
int T,t,n;
struct cb
{
    int c1,c2,c3;
}a[100005];
int max_,flag[5];
bool fg,qz;
bool cmp1(cb l,cb r)
{
    return l.c1>r.c1;
}
void f(int p,int q,int c)
{
    if(q>n)
    {
        max_=max(p,max_);
        return;
    }
    if(flag[1]>=t)
    {
        flag[2]++;
        f(p+a[q].c2,q+1,2);
        flag[2]--;
        flag[3]++;
        f(p+a[q].c3,q+1,3);
        flag[3]--;
    }
    else if(flag[2]>=t)
    {
        flag[1]++;
        f(p+a[q].c1,q+1,1);
        flag[1]--;
        flag[3]++;
        f(p+a[q].c3,q+1,3);
        flag[3]--;
    }
    else if(flag[3]>=t)
    {
        flag[2]++;
        f(p+a[q].c2,q+1,2);
        flag[2]--;
        flag[1]++;
        f(p+a[q].c1,q+1,1);
        flag[1]--;
    }
    else 
    {
        flag[2]++;
        f(p+a[q].c2,q+1,2);
        flag[2]--;
        flag[3]++;
        f(p+a[q].c3,q+1,3);
        flag[3]--;
        flag[1]++;
        f(p+a[q].c1,q+1,1);
        flag[1]--;
    }
}
void dfs(int p,int q,int c)
{
    if(q>n)
    {
        max_=max(p,max_);
        return;
    }
    if(flag[1]>=t)
    {
        flag[2]++;
        f(p+a[q].c2,q+1,2);
        flag[2]--;
    }
    else if(flag[2]>=t)
    {
        flag[1]++;
        f(p+a[q].c1,q+1,1);
        flag[1]--;
    }
    else 
    {
        flag[2]++;
        f(p+a[q].c2,q+1,2);
        flag[2]--;
        flag[1]++;
        f(p+a[q].c1,q+1,1);
        flag[1]--;
    }
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--)
    {
        cin>>n;
        t=n/2;
        max_=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].c1>>a[i].c2>>a[i].c3;
            if(a[i].c2)fg=1;
            if(a[i].c3)qz=1;
        }
        if(!fg && !qz)
        {
            sort(a+1,a+n+1,cmp1);
            int cnt=0;
            for(int i=1;i<=t;i++)cnt+=a[i].c1;
            cout<<cnt<<'\n';
            continue;
        }
        else if(!qz)
        {
            dfs(0,1,1);
            cout<<max_<<'\n';
            continue;
        }
        else f(0,1,1);
        cout<<max_<<'\n';
    }
    return 0;
}