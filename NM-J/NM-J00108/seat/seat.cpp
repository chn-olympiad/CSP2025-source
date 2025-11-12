#include<bits/stdc++.h>
using namespace std;
int n,m;
int c,r;
long long a=[];
int num;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            cin>>num;
            a[i][j]=num;
            if(a[i][j]>a[i-1][j])
            {
                r=i-1
                c=j
            }
            else if(a[i][j]>a[i-1][j-1])
            {
                r=i-1;
                c=j-1;
            }
            else
            {
                r=i;
                c=j;
            }
        }
    }
    cout<<c<<" "<<r;
    return 0;
}
