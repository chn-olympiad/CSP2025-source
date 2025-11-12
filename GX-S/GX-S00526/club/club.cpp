#include<bits/stdc++.h>
using namespace std;
struct node{
    int a,b,c;
}p[100010];
int q[100010];
int ret=0;
void judge(int n,int best,int start)
{
    if(best==n)
    {
        int cnt=0;
        int x=0,y=0,z=0;
        for(int i=1; i<=n; i++)
        {
            if(q[i]==1)
            {
                x++;
                cnt+=p[i].a;
            }
            if(q[i]==2)
            {
                y++;
                cnt+=p[i].b;
            }
            if(q[i]==3)
            {
                z++;
                cnt+=p[i].c;
            }
        }
        if(x>n/2||y>n/2||z>n/2)
        {
            return ;
        }
        ret=max(ret,cnt);
    }
    for(int i=start; i<=n; i++)
    {
        q[best+1]=1;
        judge(n,best+1,i+1);
        q[best+1]=2;
        judge(n,best+1,i+1);
        q[best+1]=3;
        judge(n,best+1,i+1);
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
        {
            scanf("%d%d%d",&p[i].a,&p[i].b,&p[i].c);
        }
        ret=0;
        judge(n,0,1);
        printf("%d\n",ret);
    }
    return 0;
}
