#include <bits/stdc++.h>
using namespace std;
struct edge{
    int a,b,c;
};
int t,n,sum;
int e;
edge d[100005],u[3];
bool cmp(edge x,edge y){
    return x.a>=y.a;
}
void f(){
   priority_queue<int> q[3];
   sum=0;
   for(int i=0;i<n;i++)
    {
        if(q[d[i].b].size()<n/2)
        {
            q[d[i].b].push(d[i].c);
            sum+=d[i].a;
        }
        else
        {
            e=q[d[i].b].top();
            if(d[i].c<e)
            {
                q[d[i].b].pop();
                q[d[i].b].push(d[i].c);
                sum+=d[i].a+e;
            }
            else
            {
                sum+=d[i].a+d[i].c;
            }
        }
    }
    printf("%d\n",sum);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    for(int l=1;l<=t;l++)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d %d %d",&u[0].a,&u[1].a,&u[2].a);
            u[0].b=0,u[1].b=1,u[2].b=2;
            sort(u,u+3,cmp);
            d[i].a=u[0].a,d[i].b=u[0].b,d[i].c=u[1].a-u[0].a;
        }
        f();
    }
    return 0;
}
