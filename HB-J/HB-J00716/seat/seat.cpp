#include<bits/stdc++.h>
#define byGyf return
using namespace std;
int n,m,a[105]={0};
int t;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    t=a[1];
    sort(a+1,a+1+n*m);
    //for(int i=1;i<=n*m;i++)
    //{
    //    cout<<a[i]<<" ";
    //}
    int x=1,y=1,cnt=m*n;
    while(cnt>0)
    {
        while(x<=n)
        {
            if(a[cnt]==t)
            {
                cout<<y<<" "<<x;
                return 0;
            }
            x++;
            cnt--;
        }
        x=n;
        y++;
        if(a[cnt]==t)
        {
            cout<<y<<" "<<x;
            return 0;
        }
        while(x>=1)
        {
            if(a[cnt]==t)
            {
                cout<<y<<" "<<x;
                return 0;
            }
            x--;
            cnt--;
        }
        x=1;
        y++;
        if(a[cnt]==t)
        {
            cout<<y<<" "<<x;
            return 0;
        }
    }
    byGyf 0;
}
