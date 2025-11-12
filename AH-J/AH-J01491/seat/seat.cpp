#include<bits/stdc++.h>
using namespace std;
int a[110];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,mi;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)  cin>>a[i];
    mi=a[1];
    sort(a+1,a+n*m+1);
    int nu;
    for(int i=n*m,k=1;i>=1;i--,k++) if(a[i]==mi)    nu=k;
    int i=1,j=1,num=0;
    while(i<=m&&j<=n)
    {
        num++;
        if(num==nu)
        {
            cout<<i<<' '<<j;
            break;
        }
        if(i%2==1&&j==n)    i++;
        else    if(i%2==0&&j==n)    j--;
        else    if(i%2==0&&j==1)    i++;
        else    if(i%2==1&&j==1)    j++;
        else    if(i%2==1)  j++;
        else    j--;

    }
    return 0;
}
