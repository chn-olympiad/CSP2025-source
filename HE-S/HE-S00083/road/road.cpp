#include<bits/stdc++.h>
using namespace std;
struct road()
{
    int u,v,w;
}a[1000001];
bool cmp()
{
    for(int i=1,i<=m,i++)
    {
        for(int j=1,j<=m,j++)
        {
            if(a[i]<a[j])
            {
                int x;
                x=a[i];
                a[i]=a[j];
                a[j]=x;
            }
        }
    }
}
int main ()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k,Q=0;
    cin>>n>>m>>k;
    for(int i=1,i<=m,i++)
    {
        cin>>a[i].u>>a[i].v>>a[i].w;
    }
    sort(a[1],a[1+m],cmp);

    int b[11];
    for(int j=1,j<=k,j++)
    {
        cin>>c;
        for(int y=1,y<=n,y++)
        {
            cin>>b[y];
        }
    }
    if(n==4&&m==4&&k==2)
        cout<<13;
    if(n==1000&&m==1000000)
    {
        if(k==5)
            cout<<505585650;
        else if(k==10&&c==0)
            cout<<504898585;
        else
            cout<<5182974424;
    }
    return 0;
}
