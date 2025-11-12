#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],grade,num;
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
    grade=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==grade)
        {
            num=i;
        }
    }
    int x=(num-1)/n+1,y;
    if((num-1)/n%2==0)
    {
        y=(num-1)%n+1;
    }
    else
    {
        y=n-(num-1)%n;
    }
    cout<<x<<" "<<y;
    return 0;
}
