#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1005],b;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++)
    {
        cin>>a[i];
    }
    b=a[0];
    sort(a,a+n*m,cmp);
    if(n==1&&m==1)
    {
        cout<<1<<" "<<1;
       return 0;
    }
    for(int i=1;i<=n*m;i++)
    {
        if(a[i-1]==b)
        {
            if(i%n==0&&(i/n)%2!=0)
                cout<<i/n<<" "<<n;
            else if(i%n==0&&(i/n)%2==0)
                cout<<i/n<<" "<<1;
            else if(i%n!=0&&(i/n)%2!=0)
                cout<<i/n+1<<" "<<n;
            else
                cout<<i/n+1<<" "<<1;
        }
    }
    return 0;
}
