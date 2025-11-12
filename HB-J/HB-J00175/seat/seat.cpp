#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105],sum=1;
int x=1,y=1;
int flag=1;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
        if(a[i]>a[1])
        {
            x+=flag;
            if(x>n||x<1)
            {
                y++;
                flag=0-flag;
                if(x>n) x=n;
                else x=1;
            }
        }
    }
    cout<<y<<" "<<x<<endl;
    return 0;
}