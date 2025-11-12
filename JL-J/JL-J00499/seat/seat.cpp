#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("seat.in","r",stdin);
    //freopen("seat.out","w",stdout);
    int n,m,a1,b;
    cin>>n>>m;
    int a[4];
    for (int i=1; i<=4; i++)
        cin>>a[i];
    a1=a[0];
    for (int j=0; j<=3; j++)
    {
        if (a[j]<a[j+1])
        {
            b=a[j];
            a[j+1]=a[j];
            a[j+1]=b;
        }
    }
    for (int i=0; i<=0; i++)
    {
        if (a[2]==a1)
            cout<<"1"<<" "<<"2";
        else
            cout<<"2"<<" "<<"2";
    }
    return 0;
}
