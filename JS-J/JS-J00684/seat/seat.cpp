#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
int a[1005];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int tot=n*m;
    for(int i=1;i<=tot;i++)
    {
        cin>>a[i];
    }
    int k=a[1];
    sort(a+1,a+tot+1,cmp);
    int x=1,y=1;
    for(int i=1;i<=tot;i++)
    {

        if(a[i]==k)
        {
            cout<<y<<" "<<x;
            return 0;
        }
        if(i%n==0)
        {
            y++;
        }
        else
        {
            if(y%2==0)x--;
            else x++;
        }
    }
    return 0;
}
