#include<bits/stdc++.h>
using namespace std;
long long t;
struct xx{
    int m,b;
};
struct node{
    xx o[5];
    int id,he=0,tong[4]={0};
};
bool cmp(xx a,xx b)
{
    return a.m>b.m;
}
bool cmb(node a,node b)
{
    if(a.o[1].m!=b.o[1].m)return a.o[1].m>b.o[1].m;
    if(a.o[2].m!=b.o[2].m)return a.o[2].m>b.o[2].m;
    return a.o[3].m>b.o[3].m;
}
queue<node> q;
int bfs(int n,int k,node p[])
{
    cout<<k<<" ";
    int max_=0;
    while(!q.empty())
    {
        node f=q.front();
        q.pop();
        for(int i=1;i<=3;i++)
        {
            if(f.tong[f.o[i].b]<k)
            {
                if(f.id==n)
                {
                    max_=max(max_,f.he+f.o[i].m);
                    continue;
                }
                node l=p[f.id+1];
                l.he=f.he+f.o[i].m;
                l.tong[1]=f.tong[1],l.tong[2]=f.tong[2],l.tong[3]=f.tong[3];
                l.tong[f.o[i].b]++;
                q.push(l);
            }
        }
    }
    return max_;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n,k,tong[4]={0};
        bool f1=0,f2=0;
        node p[100005];
        scanf("%d",&n);
        k=n,k=k/2;
        for(int j=1;j<=n;j++)
        {
            scanf("%d%d%d",&p[j].o[1].m,&p[j].o[2].m,&p[j].o[3].m);
            p[j].o[1].b=1,p[j].o[2].b=2,p[j].o[3].b=3;
            if(p[j].o[2].m!=0)f1=1;
            if(p[j].o[3].m!=0)f2=1;
            sort(p[j].o+1,p[j].o+4,cmp);
            p[j].id=j;
        }
        if(f1==0&&f2==0)
        {
            long long ans=0;
            sort(p+1,p+n+1,cmb);
            for(int j=1;j<=k;j++)
                ans=ans+p[j].o[1].m;
        }
        q.push(p[1]);
        cout<<bfs(n,k,p)<<endl;
    }
    return 0;
}
