#include <bits/stdc++.h>
using namespace std;
int m,n,seat[15][15],a[105],l,sum;
int num[100000005],cou=1;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>l;
    a[1]=l;
    for(int i=2;i<=m*n;i++) cin>>a[i];
    sort(a+1,a+n*m+1);
    for(int i=m*n;i>1;i--)if(a[i]>l)sum++;
    if((sum/n+1)%2==0)cout<<sum/n+1<<' '<<n-sum%n;
    else cout<<sum/n+1<<' '<<sum%n+1;
    return 0;
}
