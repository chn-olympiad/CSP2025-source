#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[10005],x;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>a[i];
    int r=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++)
        if(a[i]==r)
            x=i;
    int w=x/n;
    int q=x%n,d;
    cout<<x<<endl;
    if(q!=0)
    {
        w++;
    }
    if(q==0)
    {
        if(w%2==0)
            d=1;
        else
            d=n;
    }
    else  if(q!=0)
    {
        if(w%2==0)
            d=n-q+1;
        else
            d=q;
    }
    cout<<w<<" "<<d;

    return 0;
}
