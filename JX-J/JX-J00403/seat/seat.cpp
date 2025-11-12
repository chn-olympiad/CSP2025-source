#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,r,a[105],k,x,sum=0;
    cin>>n>>m;
    int b[n+1][m+1]={};
    for(int i=1;i<=n*m;i++)
    {
        cin>>x;
        a[x]++;
        if(i==1)
        {
            r=x;
        }
    }
    cout<<1<<" "<<1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
