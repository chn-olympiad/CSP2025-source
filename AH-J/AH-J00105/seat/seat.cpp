#include<bits/stdc++.h>
using namespace std;
int a[105],b,c,d;
bool ljy(int x,int y)
{
    return x>y;
}
int main(void)
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>b>>c;
    for(int i=0;i<b*c;i++)
        cin>>a[i];
    d=a[0];
    sort(a,a+b*c,ljy);
    for(int i=0;i<b*c;i++)
    {
        if(a[i]==d)
        {
            cout<<i/b+1<<" ";
            if((i/b+1)%2==0)
                cout<<c-i%b;
            else
                cout<<i%b+1;
        }
    }
    return 0;
}
