#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,l=0;
    cin>>n>>m;
    int a[n*m];
    int b[n][m];
    for(int i=0;i<n*m;i++)
    {
        cin>>a[i];
    }
    int k=a[0];
    sort(a+1,a+1+n*m);
    int i=0;j=0;

    while(j==m&&i==x)
    {
        if(m%2==0) int x=n-1;
        else int x=0;
        if(j%2==0)i++;
        else i--;
        if(i==x)j++;
        b[i][j]=a[l];
        l++;
        if(b[i][j]==k)
        {
            cout<<i<<" "<<j;
            break;
        }
    }
    return 0;
}
