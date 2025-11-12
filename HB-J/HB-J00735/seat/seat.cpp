#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int h,l,p;
    cin>>h>>l;
    int n = h*l;
    int a[100100];
    for(int i = 0;i<n;i++)
    {
        cin>>a[i];
    }
    int f = a[1];
    for(int i=0;i<n-1;i++)
    {
        int c = a[i];
        a[i] = a[i+1];
        a[i+1] = c;
    }
    for(int i = 0;i<n;i++)
    {
        if(i = f)
        {
            p = i;
            break;
        }
    }
    cout<<p/l<<" "<<p%h;

    return 0;
}
