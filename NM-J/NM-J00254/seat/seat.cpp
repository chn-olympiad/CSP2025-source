#include<iostream>
#include<algorithm>
using namespace std;
int a[110];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    sort(a+2,a+(n*m)+1);
    int fir=a[1];
    int ffii=1;
    for(int i=2;i<=n*m;i++)
    {
        if(fir>a[i])ffii++;
        else break;
    }
    ffii=(n*m)-ffii+1;
    ffii--;
    int dx=(ffii)/n+1;
    int dy;
    if(dx%2==1)
    {
        dy=ffii%n+1;
    }
    else if(dx%2==0)
    {
        dy=n-(ffii%n);
    }
    cout<<dx<<" "<<dy;
    return 0;
}
