#include<bits/stdc++.h>
using namespace std;
int sc[10005];
int r,c;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,R,num;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
            cin>>sc[i];
    R=sc[1];
    sort(sc+1,sc+n*m+1);
    for(int i=1;i<=n*m;i++)
    {
        if(sc[i]==R)
        {
            num=n*m-i+1;;
            break;
        }
    }
    if(num%n==0)    c=num/n;
    else            c=num/n+1;
    if(c%2==1)  r=num-(c-1)*n;
    else        r=n-(num-(c-1)*n)+1;
    cout<<c<<' '<<r;
    return 0;
}
