#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[105];

int sum;
int aa;
int pos;
int Up(int x,int y)
{
    if(x%y==0)
    {
        return x/y;
    }
    else
    {
        return x/y+1;
    }
}
int ansdx;

int ansx,ansy;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }

    sum=n*m;

    aa=a[1];
    sort(a+1,a+n*m+1);
    auto it=lower_bound(a+1,a+n*m+1,aa);
    pos=sum-(it-a)+1;

    ansy=Up(pos,n);
    ansdx=pos;
    ansdx%=n;
    if(pos/n*n==pos)
    {
        ansdx=m;
    }
    if(ansy%2==0)
    {
        ansx=n-ansdx+1;
    }
    else if(ansy%2==1)
    {
       ansx=ansdx;
    }

    cout<<ansy<<' '<<ansx<<endl;

    return 0;
}
