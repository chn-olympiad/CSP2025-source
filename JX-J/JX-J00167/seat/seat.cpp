#include<bits/stdc++.h>
using namespace std;
int a[101];
int b[11][11];
int n,m;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    int k=a[1];
    sort(a+1,a+n*m+1,cmp);
    int x=1,y=1;
    for(int i=1;i<=n*m;i++)
    {
        b[x][y]=a[i];
        if(a[i]==k)
        {
            cout<<y<<" "<<x;
            break;
        }
        if(x==n) y++;
        if(y%2==0) x--;
        else x++;
    }
    return 0;
}
