#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005],ans=1;
struct node
{
    int l,r;
}b[5000005];
bool cmp(node x,node y)
{
    if(x.r!=y.r) return x.r<y.r;
    else return x.l<y.l;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d,%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int j=0;
    for(int l=1;l<=n;l++)
    {
        int x=a[l];
        if(x==k)
        {
            b[++j].l=l,b[j].r=l;
        }
        for(int r=l+1;r<=n;r++)
        {
            x=x^a[r];
            if(x==k)
            {
                b[++j].l=l,b[j].r=r;
            }
        }
    }
    sort(b+1,b+1+j,cmp);
    int end=b[1].r;
    for(int i=2;i<=j;i++)
    {
        if(b[i].l<=end) continue;
        ans++,end=b[i].r;
    }
    printf("%d\n",ans);
    return 0;
}