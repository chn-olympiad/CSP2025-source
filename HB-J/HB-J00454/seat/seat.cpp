#include<bits/stdc++.h>
using namespace std;
bool f(int a,int b)
{
    if(a>b)
    {
        return 1;
    }
    return 0;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n*m+5];
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int u=a[1];
    sort(a+1,a+n*m+1,f);
    int x=1,y=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=(i%2+1)%2*(m-1)+1;j<=m;j+=x)
        {
            if(j==0)
            {
                break;
            }
            if(a[++y]==u)
            {
                cout<<i<<" "<<j<<"\n";
                return 0;
            }
        }
        if(x==1)
        {
            x=-3;
        }
        x+=2;
    }
    return 0;
}
