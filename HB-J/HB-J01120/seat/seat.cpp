#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
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
    {
        cin>>a[i];
    }
    int r=a[1];
    sort(a+1,a+1+n*m,cmp);
    int x=0,y=1,t=1,cnt=0;
    while(cnt<n*m)
    {
        x+=t;
        cnt++;
        if(a[cnt]==r)
        {
            cout<<y<<" "<<x;
            break;
        }
        if(t==1&&x==n)
        {
            y++;
            cnt++;
            if(a[cnt]==r)
            {
                cout<<y<<" "<<x;
                break;
            }
            t=-t;
        }
        if(t==-1&&x==1)
        {
            y++;
            cnt++;
            if(a[cnt]==r)
            {
                cout<<y<<" "<<x;
                break;
            }
            t=-t;
        }
    }
    return 0;
}
