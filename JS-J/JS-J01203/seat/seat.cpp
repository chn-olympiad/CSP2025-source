#include <bits/stdc++.h>
using namespace std;

const int maxn=105;
int n,m,a[maxn],cnt=1;

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;++i)
    {
        cin>>a[i];
        if(a[i]>a[1])
            cnt++;
    }
    if((cnt/n+1)%2!=1)
        cout<<cnt/n+1<<" "<<cnt%n+1;
    else
        cout<<cnt/n+1<<" "<<n-cnt%n-1;
    return 0;
}
