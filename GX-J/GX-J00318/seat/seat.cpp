#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,h=1,l=1;
    cin>>n>>m;
    int d=m*n;
    int a[d+1]={0};
    for(int i=1;i<=d;i++)
    {
        cin>>a[i];
    }
    int c=a[1];
    sort(a+1,a+d+1);
    for(int i=d;i>=1;i--)
    {
        if(c==a[i])
        {
            cout<<l<<" "<<h;
            return 0;
        }
        if(l%2!=0)
        {
            h++;
        }
        else
        {
            h--;
        }
        if(h>n||h<1)
        {
            if(h>n)
            {
                h=n;
            }
            else
            {
                h=1;
            }
            l++;
        }
    }
    return 0;
}
