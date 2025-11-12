#include<bits/stdc++.h>
using namespace std;
int n,m,num,cnt=0,ansx,ansy;
int a[105];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>num;
    a[1]=num;
    for(int i=2;i<=n*m;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n*m+1);
    for(int i=n*m;i>=1;i--)
    {
        cnt++;
        if(num==a[i]) break;
    }
    if(cnt%n==0) ansy=cnt/n;
    else ansy=cnt/n+1;
    ansx=cnt%n;
    if(ansx==0) ansx=n;
    if(ansy%2==0) ansx=n+1-ansx;
    cout<<ansy<<' '<<ansx;
    return 0;
}
