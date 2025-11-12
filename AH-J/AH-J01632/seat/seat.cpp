#include<bits/stdc++.h>
using namespace std;
int a[20][20];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,i,j;
    cin>>n>>m;
    int s=1;
    cin>>a[1][1];
    int k=a[1][1];
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
        {
            if(i==1&&j==1)
                continue;
            cin>>a[i][j];
            if(a[i][j]>k)
                s++;
        }
    if(s%n==0)
    {
        cout<<s/n<<" ";
        if((s/n)%2==0)
        {
            cout<<1<<endl;
            return 0;
        }
        cout<<n<<endl;
        return 0;
    }
    cout<<s/n+1<<" ";
    if((s/n+1)%2==0)
    {
         cout<<n-(s%n)+1<<endl;
         return 0;
    }
    cout<<s%n<<endl;
    return 0;
}
