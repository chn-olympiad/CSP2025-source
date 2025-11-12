#include<bits/stdc++.h>
using namespace std;
int a[10005]={};
bool cmp(int x,int y)
{
    return x>y;
}
int s[205][205]={};
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int keya=a[1];
    sort(a+1,a+n*m+1,cmp);
    int l=1;
    int x=1;
    int y=1;
    for(int i=1;i<=n*m+1;i++)
    {
        s[x][y]=a[i];
        if(a[i]==keya)
        {
            cout<<y<<' '<<x<<endl;
            break;
        }
        if(l==1)
        {
            x++;
        }
        else if(l==2)
        {
            x--;
        }
        else
        {
            y++;
        }
        if(x==n&&y%2)
        {
            l=3;
        }
        if(x==n&&y%2==0)
        {
            l=2;
        }
        if(x==1&&y%2==0)
        {
            l=3;
        }
        if(x==1&&y%2==1)
        {
            l=1;
        }
    }
    return 0;
}
