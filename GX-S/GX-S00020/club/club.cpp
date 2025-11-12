#include <bits/stdc++.h>
using namespace std;

struct ED{
    int a,b,c;
}cs;
bool bj(ED a,ED b)
{
    return a.a>b.a;
}
ED v[100001];
int n,T;
long long ans=0;

void dfs(int w,int n1,int n2,int n3,long long z)
{
    if(w>n)
    {
        ans=max(z,ans);
        return;
    }
    if(n1<n/2)  dfs(w+1,n1+1,n2,n3,z+v[w].a);
    if(n2<n/2)  dfs(w+1,n1,n2+1,n3,z+v[w].b);
    if(n3<n/2)  dfs(w+1,n1,n2,n3+1,z+v[w].c);
}
void dfs_jq(int w,int n1,int n2,long long z)
{
    if(w>n)
    {
        ans=max(z,ans);
        return;
    }
    if(n1<n/2)  dfs_jq(w+1,n1+1,n2,z+v[w].a);
    if(n2<n/2)  dfs_jq(w+1,n1,n2+1,z+v[w].b);
}

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>n;
        int bs=1;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d",&v[i].a,&v[i].b,&v[i].c);
            if(v[i].c!=0)   bs=3;
            if(v[i].b!=0 && v[i].c==0)   bs=2;
        }

        if(bs==1)
        {
            sort(v+1,v+1+n,bj);
            long long ans=0;
            for(int i=1;i<=n/2;i++) ans+=v[i].a;
            cout<<ans<<endl;
            continue;
        }
        if(bs==2)
        {
            ans=0;
            dfs_jq(0,0,0,0);
            cout<<ans<<endl;
            continue;
        }
        ans=0;
        dfs(0,0,0,0,0);
        cout<<ans<<endl;
    }
    return 0;
}
