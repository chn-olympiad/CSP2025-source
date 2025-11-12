#include<cstdio>
#include<iostream>
using namespace std;

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,r,cnt=1;
    cin>>n>>m;
    cin>>r;
    for(int i=2;i<=n*m;i++)
    {
        int a;
        cin>>a;
        if(a>r)cnt++;
    }
    if((cnt/n+1-(cnt%n==0))%2==1)
    {
        cout<<cnt/n+1-(cnt%n==0)<<" "<<(cnt%n==0?n:cnt%n);
    }
    else
    {
        cout<<cnt/n+1-(cnt%n==0)<<" "<<n-(cnt%n==0?n:cnt%n)+1;
    }
    return 0;
}
