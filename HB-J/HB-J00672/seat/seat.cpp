#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n*m+1],b,c;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    c=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++) if(a[i]==c) {b=i;break;}
    if(b%n==0)
    {
        cout<<b/n<<" ";
        if(b/n%2==0) cout<<1;
        else cout<<n;
    }
    else
    {
        cout<<b/n+1<<" ";
        if((b/n+1)%2==0)
        {
            cout<<n-b%n+1;
        }
        else
        {
            cout<<b%n;
        }
    }
    return 0;
}
