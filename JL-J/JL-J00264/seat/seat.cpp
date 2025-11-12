#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    int a[1010];
    cin>>n>>m;
    cin>>a[1];
    int x=a[1];
    for(int i=2;i<=n*m;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n*m);
    int ans;
    for(int i=n*m;i>=1;i--)
    {
        if(a[i]==x){ans=n*m-i+1;break;}
    }
    int h,l;
    h=ans/n;
    if(ans%n!=0)h++;
    l=ans%(2*n);
    if(l==0)l=1;
    if(l>n) l=2*n-l+1;
    cout<<h<<" "<<l;
    return 0;
}
