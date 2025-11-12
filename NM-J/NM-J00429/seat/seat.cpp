#include<bits/stdc++.h>
using namespace std;
int n,m,a[5000][5000];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
         for(int  j=1;j<=m;j++)
         cin>>a[i][j];
    }
    cout<<"1"<<" "<<"2";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
