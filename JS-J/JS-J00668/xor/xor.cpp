#include <bits/stdc++.h>
using namespace std;
const int N=500010;
int a[N];
struct node
{
    int l,r;
};
int cmp(node x,node y)
{
    return x.r<y.r;
}
node e[N];
int main()
{
    freopen("xor.in", "r",stdin);
    freopen("xor.out", "w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int len=0;
    for(int i=1;i<=n;i++)
    {
        int fina=a[i];
        if(fina==k)
        {
            len++;
            e[len].l=i,e[len].r=i;
        }
        for(int j=i+1;j<=n;j++)
        {
            fina=(fina^a[j]);
            if(fina==k)
            {
                len++;
                e[len].l=i,e[len].r=j;
            }
        }
    }
    if(len==0)
    {
        cout<<0;
        return 0;
    }
    sort(e+1,e+len+1,cmp);
    int cnt=1;
    int f=e[1].r;
    for(int i=2;i<=len;i++)
    {
        if(e[i].l>f)
        {
            cnt++;
            f=e[i].r;
        }
    }
    cout<<cnt;
    return 0;
}
