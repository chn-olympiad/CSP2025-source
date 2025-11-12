#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int x=m*n;
    short int a[x+1];
    for(int i=1; i<=x; i++)
    {
        cin>>a[i];
    }
    int Rs=a[1];
    int pos;
    sort(&a[1],&a[x+1]);
    int b[x+1];
    int j=1;
     for(int i=x; i>0; i--)
    {
        b[j]=a[i];
        j++;
    }
    for(int i=1; i<=x; i++)
    {
        if(b[i]==Rs)
        {
            pos=i;
        }
    }
    int c=pos/n;
    int r=pos%n;
    if(r>0)c++;
    if(r==0)r=m;
    if(c%2==0){
        r=m-r+1;
    }
    cout<<c<<' '<<r;
    return 0;
}
