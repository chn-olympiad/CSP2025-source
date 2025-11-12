#include<bits/stdc++.h>
using namespace std;
int a[105];
int n,m,cot,s,seatx,x,y;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    cin>>n>>m;
    cot=n*m;
    for(int i=1;i<=cot;i++)
    {
        cin>>a[i];
    }
    s=a[1];
    sort(a+1,a+cot+1,cmp);
    for(int i=1;i<=cot;i++)
    {
        if(a[i]==s)
        {
            seatx=i;
        }
    }
    if(seatx%n==0)
    {
            if((seatx/n)%2==0)
            {
                cout<<(seatx/n)<<" "<<1<<endl;
            }
            else{
                cout<<(seatx/n)<<" "<<m<<endl;
            }
    }
    else
    {
        x=seatx/n;y=seatx%n;
        x++;
        if(x%2==0)
        {
            cout<<x<<" "<<m-y+1<<endl;
        }
        else
        {
            cout<<x<<" "<<y<<endl;
        }
    }
    return 0;
}
