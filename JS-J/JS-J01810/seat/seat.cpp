#include<bits/stdc++.h>
using namespace std;
int n,m,b[10005],x,w,w1;
int cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>b[i];
        if(i==1)
        {
            x=b[i];
        }
    }
    sort(b+1,b+1+n*m,cmp);
    for(int i=1;i<=n*m;i++)
    {
        if(b[i]==x)
        {
            w=i;
        }
    }
    w1=w/(n*2)+1;
    w=w%(n*2);
    if(w>n)
    {
        cout<<w1*2<<' '<<w-n/2;
    }
    if(w<=n)
    {
        cout<<w1*2-1<<' '<<w;
    }
    return 0;
}
