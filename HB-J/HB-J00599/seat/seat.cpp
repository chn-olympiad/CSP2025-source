#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>a[0];
    a[n*m]=-1;
    int ans=0;
    for(int i=1;i<m*n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+m*n,cmp);
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]<a[0])
        {
            ans=i;
            break;
        }
    }
    if((ans-1)/m%2==0)
    {
        cout<<(ans-1)/m+1<<" ";
        cout<<(ans-1)%n+1;
    }else{
        cout<<(ans-1)/m+1<<" ";
        cout<<n-(ans-1)%n+1;
    }

    return 0;
}


