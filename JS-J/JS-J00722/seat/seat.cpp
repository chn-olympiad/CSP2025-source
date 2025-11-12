#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    cin>>a[i];
    int t=a[1];
    sort(a+1,a+n*m+1,cmp);
    int c=1,r=1;
    for(int i=1;i<=n*m;i++)
    {
        if(t==a[i])
        {
            cout<<c<<" "<<r;
            return 0;
        }
        if(c%2==0&&r==1)
            c++;
        else if(c%2!=0&&r==n)
            c++;
        else if(c%2==0&&r!=1)
            r--;
        else if(c%2!=0&&r!=n)
            r++;
    }
    return 0;
}
