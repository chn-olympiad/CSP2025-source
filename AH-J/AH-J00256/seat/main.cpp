#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,c = 1,r = 1;
    int a[101];
    cin>>m>>n;
    for(int i = 0;i<n*m-1;i++)
    {
        cin>>a[i];
        if(a[i]<a[i+1])
        {
            r++;
        }
        if(r%n == 0&&r>n)
        {
            c++;
            r=n;
        }
    }

    cout<<c<<" "<<r;
    return 0;
}
