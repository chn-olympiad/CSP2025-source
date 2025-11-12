#include<bits/stdc++.h>
using namespace std;
const int maxn=101000;
int a[maxn][3];
struct node
{
    int a[3],mx,md,mn;
    friend bool operator >(node a,node b)
    {
        return a.mx-a.md<b.mx-b.md;
    }
    friend bool operator <(node a,node b)
    {
        return a.mx-a.md>b.mx-b.md;
    }
};
priority_queue<node>q1;
priority_queue<node>q2;
priority_queue<node>q3;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    scanf("%d",&T);
    int n,m,i,j,k,l,sum=0;
    node tmp;
    while(T--)
    {
        while(q1.size()!=0)q1.pop();
        while(q2.size()!=0)q2.pop();
        while(q3.size()!=0)q3.pop();
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
            tmp.a[0]=a[i][0];
            tmp.a[1]=a[i][1];
            tmp.a[2]=a[i][2];
            sort(a[i],a[i]+3);
            tmp.mx=a[i][2];
            tmp.md=a[i][1];
            tmp.mn=a[i][0];
            if(tmp.a[0]>=tmp.a[1]&&tmp.a[0]>=tmp.a[2])q1.push(tmp);
            else if(tmp.a[1]>=tmp.a[0]&&tmp.a[1]>=tmp.a[2])q2.push(tmp);
            else q3.push(tmp);
            sum+=a[i][2];
        }
        if(q1.size()>n/2)
        {
            while(q1.size()>n/2)
            {
                tmp=q1.top();
                sum-=tmp.mx;
                sum+=tmp.md;
                q1.pop();
            }
        }
        else if(q2.size()>n/2)
        {
            while(q2.size()>n/2)
            {
                tmp=q2.top();
                sum-=tmp.mx;
                sum+=tmp.md;
                q2.pop();
            }
        }
        else if(q3.size()>n/2)
        {
            while(q3.size()>n/2)
            {
                tmp=q3.top();
                sum-=tmp.mx;
                sum+=tmp.md;
                q3.pop();
            }
        }
        printf("%d\n",sum);
        sum=0;
    }
    return 0;
}
