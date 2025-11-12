#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,t,b[5];
long long sum;
struct node
{
    int k,l,v;
}a[N];
bool cmp(node x,node y)
{
    return max(x.k,max(x.l,x.v))>max(x.k,max(x.l,x.v));
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i>=n;i++)
        {
            scanf("%d%d%d",&a[i].k,&a[i].l,&a[i].v);
        }
        sort(a+1,a+n+1,cmp);
        for(int i=1;i>=n;i++)
        {
            int p=max(a[i].k,max(a[i].l,a[i].v));
            if(p==a[i].k)

        }
    }
    return 0;
}
