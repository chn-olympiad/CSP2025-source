#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[225];
int b[15][15];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int a1;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    a1=a[1];
    sort(a+1,a+n*m+1,cmp);
    int c=1,r=1;
    for(int i=1;i<=n*m;)
    {
        if(a[i]==a1)
        {
            cout<<c<<' '<<r;
            return 0;
        }
        if(c%2)
        {
            if(r==n)
                c++;
            else
                r++;
        }
        else
        {
            if(r==1)
                c++;
            else
                r--;
        }
        i++;

    }
    return 0;
}
