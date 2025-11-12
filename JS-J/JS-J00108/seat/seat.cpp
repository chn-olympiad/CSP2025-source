#include<bits/stdc++.h>
using namespace std;
int a[110];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int aim;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    aim=a[1];
    sort(a+1,a+n*m+1,cmp);
    int num;
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==aim)
        {
            num=i;
        }
    }
    int l,h;
    l=(num-1)/n+1;
    cout<<l<<" ";
    if(l%2==1)
    {
        h=(num-1)%n+1;
        cout<<h;
    }
    else
    {
         h=n-(num-1)%n;
         cout<<h;
    }
    return 0;
}
