#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,a[105];

bool cmp(int x,int y)
{
    return x>y;
}

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int s=n*m;
    for(int i=1;i<=s;i++)
    {
        cin>>a[i];
    }
    int r=a[1],pos=1;
    sort(a+1,a+s+1,cmp);
    for(int i=1;i<=s;i++)
    {
        if(a[i]==r) pos=i;
    }
    if(pos%n==0)
    {
        cout<<pos/n<<" ";
        if((pos/n)%2!=0) cout<<n;
        else cout<<1;
    }
    if(pos%n!=0)
    {
        cout<<pos/n+1<<" ";
        if((pos/n+1)%2!=0) cout<<pos%n;
        else cout<<n-(pos%n)+1;
    }
    return 0;
}
