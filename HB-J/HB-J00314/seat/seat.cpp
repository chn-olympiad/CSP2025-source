#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[110],x;

bool cmp(int x,int y)
{
    return x>y;
}

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    x=a[1];
    sort(a+1,a+1+n*m,cmp);
    int q=0,i=0,j=0;
    while(1)
    {
        q++;
        if(j%2==1) i++;
        else i--;
        if(i>n||i<1) j++;
        if(i>n) i=n;
        if(i<1) i=1;
        if(a[q]==x) break;
    }
    cout<<j<<' '<<i;
    return 0;
}
