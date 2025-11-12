#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("r","seat.in",stdin);
    freopen("w","seat.out",stdout);
    int n,m,a[1086];
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>a[i];
    int r=a[1];
    int fx=1,h=1,l=1;
    for(int i=1;i<=n*m;i++)
    {
        if(fx==1)
        {
            h++;
            if(h>=n)
            {
                h--;
                l++;
                fx=2;
            }
        }
        else if(fx==2)
        {
            h--;
            if(h<=1)
            {
                h++;
                l++;
                fx=1;
            }
        }
        if(a[i]==r)
        {
            cout<<h<<' '<<l;
            return 0;
        }
    }
    return 0;
}
