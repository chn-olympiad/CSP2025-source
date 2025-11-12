#include <iostream>
using namespace std;
int a[105];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n,k=0;
    cin>>m>>n;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=m*n;i++)
    {
        if(a[i]>a[1])
        {

            k++;
        }
    }
    int h=m*n-k;
    int lie=0,hang=0;
    if(h%m==0)
    {
        lie=n-(h/m)+1;
        if(lie%2==1)
        {
            hang=1;
        }
        else
        {

            hang=m;
        }
    }
    else
    {
        lie=n-(h/m);
        if((n-(h/m))%2==1)
        {
            hang=m-(h%m)+1;
        }
        else
        {
            hang=h%m;
        }
    }

    cout<<lie<<" "<<hang;


}
