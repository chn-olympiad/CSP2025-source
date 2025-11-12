#include<bits/stdc++.h>
using namespace std;
struct arry
{
    int v;
    bool f=false;
};
arry a[10010];
int n,m,r,c;
bool mcmp(arry x,arry y)
{
    return x.v>y.v;
}
void work()
{
    int pos,mx;
    for(int i=1;i<n*m;i++)
    {
        mx=-1;
        for(int j=i;j<=n*m;j++)
        {
            if(a[j].v>mx)
            {
                mx=a[j].v;
                pos=j;
            }
        }
        swap(a[pos].v,a[i].v);
        swap(a[pos].f,a[i].f);
    }
    r=0,c=1;
    int opt=1;
    for(int i=1;i<=n*m;i++)
    {
        if(r==n&&opt==1)
        {
            opt=-1;
            c++;
        }
        else if(r==1&&opt==-1)
        {
            opt=1;
            c++;
        }
        else r+=opt;
        if(a[i].f)    return;
    }
    return;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)    cin>>a[i].v;
    a[1].f=true;
    work();
    if(r==0)    r++;
    cout<<c<<' '<<r;
    return 0;
}
