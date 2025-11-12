#include<bits/stdc++.h>
using namespace std;
int a[110];
int n,m;
int b;

bool camp(int x,int y)
{
    return x>y;
}

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int x,y,z;
    x=1;
    y=1;
    z=1;
    cin>>n>>m;
    cin>>b;
    if(n==1 && m==1)
    {
        cout<<1<<" "<<1<<endl;
        return 0;
    }
    for(int i=1;i<=n*m-1;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n*m,camp);
        for(int i=1;i<=n*m;i++)
    {cout<<a[i];
        if(b<a[i])
        {
            y++;
            if(y>n)
            {
                y-=n;
                x++;
                z*=-1;
            }
        }
        else if(a[i]<b)
        {
            cout<<x<<" ";
            if(z==-1)
            cout<<n-y+1<<endl;
            else
            cout<<y<<endl;
            return 0;
        }
    }

    return 0;
}
