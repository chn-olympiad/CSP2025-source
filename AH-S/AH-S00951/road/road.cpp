#include<bits/stdc++.h>
using namespace std;
int n,m,k,c[100],fa[10005],cnt;
long long ans;
struct node{
    int x,y,v,k=0;
    friend bool operator < (const node& a,const node& b)
    {
        return a.v+c[a.k]>b.v+c[b.k];
    }
}sb;
priority_queue<node> q;
int find_(int x){
    if(fa[x]!=x)fa[x]=find_(fa[x]);
    return fa[x];
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
        fa[i]=i;
    for(int i=1,a,b,c;i<=m;i++)
    {
        scanf("%d%d%d",&sb.x,&sb.y,&sb.v);
        q.push(sb);
    }
    for(int i=1,a[10005];i<=k;i++)
    {
        cin>>c[i];
        for(int j=1;j<=n;j++)
            scanf("%d",&a[j]);
        for(int j=1;j<=n;j++)
            for(int l=j+1;l<=n;l++)
            {
                sb.x=j,sb.y=l,sb.v=a[j]+a[l];
                sb.k=i;
                q.push(sb);
            }
    }
    while(!q.empty())
    {
        node f=q.top();
        q.pop();
        int r1=find_(f.x),r2=find_(f.y);
        if(r1!=r2)
        {
            cnt++;
            fa[r2]=r1;
            ans=ans+f.v,ans=ans+c[f.k];
            c[f.k]=0;
        }
        if(cnt==n-1)break;
    }
    cout<<ans;
    return 0;
}
