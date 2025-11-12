#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long n,m,x,z,y=0;
    int a[100];
    cin >> n >> m;
    x=n*m;
    for(int i=1;i<=x;i++)
    {
        cin >> a[i];
    }
    z=a[1];
    sort(a+1,a+x+1);
    for(int i=1;i<=x;i++)
    {
        for(int j=1;j<=x;j++)
        {

            if(a[i]==z)
            {
                y=j;
                x=i-1;
            }
            a[i]=i,j;
        }
    }
    cout << y << ' ' << x;
    return 0;
}
