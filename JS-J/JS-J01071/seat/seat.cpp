#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int a[n*m+1],b=1,t,x,y;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    t=a[1];
    for(int i=1;i<=n*m-1;i++)
    {
        for(int j=i;j<=n*m-i;j++)
        {
            if(a[j]<a[j+1])
            {
                if(a[j]==t)
                {
                    b=j+1;
                }
                swap(a[j],a[j+1]);
            }
        }
    }
    x=b/(n*2);
    y=b%(n*2);
    if(y==0) cout<<x*2<<" 1";
    else if(y<=n) cout<<x*2+1<<" "<<y;
    else cout<<x*2+2<<" "<<n+n-y+1;
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    return 0;
}
