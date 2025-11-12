#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=n;i<=m;i++)
    {
        cin>>a[i];
        cout<<n<<" "<<m;
    }
   return 0;
}
