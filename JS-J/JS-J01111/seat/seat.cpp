#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n;
    cin>>m>>n;
    int a[m*n+1];
    for(int i=1;i<=m*n;i++)
    {
        cin>>a[i];
    }
    int b=a[1];
    sort(a+1,a+m*n+1);
    int c=1;
    while(1)
    {
        if(b==a[m*n-c+1])
        {
            break;
        }
        c+=1;
    }
    if(int(ceil(c*1.0/m))%2==1)cout<<ceil(c*1.0/m)<<' '<<(c-1)%m+1;
    else cout<<ceil(c*1.0/m)<<' '<<(m-(c%m))%m+1;
    return 0;
}
