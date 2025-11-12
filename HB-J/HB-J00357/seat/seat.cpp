#include <bits/stdc++.h>
using namespace std;
int b[1000005]={};
int n,m,a,c;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>c;
    b[1]=c;
    for(int i=2;i<=n*m;++i)
    {
        cin>>a;
        b[i]=a;
    }
    sort(b+1,b+n*m+1,cmp);
    for(int i=1;i<=n*m;++i)
    {
        if(b[i]==c)
        {
            cout<<(i-1)/n+1<<" ";
            if(((i-1)/n+1)%2==0)
                cout<<n+1-i%n;
            if(((i-1)/n+1)%2==1 && i%n!=0)
                cout<<i%n;
            if(((i-1)/n+1)%2==1 && i%n==0)
                cout<<n;
        }
    }
    return 0;
}
