#include<bits/stdc++.h>
using namespace std;
int n,m,a[11][11],h,l,x=1;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>a[i][j];
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(a[i][j]>a[1][1])x++;
    int k=2*n;
    if(x%k==0){
        cout<<(x/k)*2<<" "<<1;
        return 0;
    }
    else if(x%k<=n)h=x%k;
    else h=(k+1)-x%k;
    l=(x/k)*2;
    if(x%k<=n)l++;
    else l+=2;
    cout<<l<<" "<<h;
    return 0;
}
