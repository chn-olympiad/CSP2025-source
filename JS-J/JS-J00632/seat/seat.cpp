#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[100000001];
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
    int k=a[1];
    sort(a+1,a+1+n*m,cmp);
    int q=0;
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==k) q=i;
    }
    if(q%n==0)
    {
        if((q/n)%2==1)
        {
            cout<<q/n<<" "<<n;
        }
        if((q/n)%2==0)
        {
            cout<<q/n<<" "<<"1";
        }
    }
    else
    {
        if((q/n)%2==1)
        {
            cout<<q/n+1<<" "<<n+1-q%n;
        }
        if((q/n)%2==0)
        {
            cout<<q/n+1<<" "<<q%n;
        }
    }
    return 0;
}
