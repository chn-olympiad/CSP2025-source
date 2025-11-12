#include<bits/stdc++.h>
using namespace std;
long long n,m,y;
int r;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>r;
    int a[m*n+2];
    a[1]=r;
    for(int i=2;i<=n*m;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n*m+1);
    int d,f;
    d=lower_bound(a+1,a+m*n+1,r)-a;
    f=m*n-d+1;//di ji ming
    if(f%m==0)
    {
        y=m;
    }
    else
    {
        y=f%m;
    }
    cout<<(f+m-1)/m<<" "<<y;
}
