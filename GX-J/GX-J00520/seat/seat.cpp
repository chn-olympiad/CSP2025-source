#include <iostream>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int b=n*m,a[1001];
    int c=1,r=0,d;
    for(int i=1;i<=b;i++)
    {
        cin>>a[i];
        d=a[1];
        for(int i=1;i<=n;i++)
        {
            if(a[i]>d)
            {
                r++;
                if(r>n)
                {
                    r=n;
                    c++;
                }
            }
        }
    }
    cout<<c<<" "<<r<<endl;
    return 0;
}
