#include<bits/stdc++.h>
using namespace std;
struct node2
{
    int a,id;
};
struct node1
{
    node2 b[4];
}a[100005];
int n,t[100005],T;
bool cmp(node1 x,node1 y)
{
    return x.b[1].a-x.b[2].a>y.b[1].a-y.b[2].a;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while (T--)
    {
        memset(t,0,sizeof(t));
        cin>>n;
        for (int i=1;i<=n;i++)
        {
            cin>>a[i].b[1].a>>a[i].b[2].a>>a[i].b[3].a;
            a[i].b[1].id=1;
            a[i].b[2].id=2;
            a[i].b[3].id=3;
            if (a[i].b[3].a>a[i].b[2].a)
            {
                swap(a[i].b[3],a[i].b[2]);
            }
            if (a[i].b[3].a>a[i].b[1].a)
            {
                swap(a[i].b[3],a[i].b[1]);
            }
            if (a[i].b[2].a>a[i].b[1].a)
            {
                swap(a[i].b[2],a[i].b[1]);
            }
        }
        sort(a+1,a+n+1,cmp);
        int ans=0;
        for (int i=1;i<=n;i++)
        {
            if (t[a[i].b[1].id]+1>n/2)
            {
                t[a[i].b[2].id]++;
                ans+=a[i].b[2].a;
            }
            else
            {
                t[a[i].b[1].id]++;
                ans+=a[i].b[1].a;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}