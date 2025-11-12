#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n*m];
    for(int i=0;i<n*m;i++)
    {
        cin>>a[i];
    }
    int g=a[0];
    for(int i=0;i<m*n-1;i++)
    {
        for(int j=i+1;j<m*n;j++)
        {
            if(a[i]<a[j])
            {
                swap(a[i],a[j]);
            }
        }
    }
    int u;
    for(int i=0;i<n*m;i++)
    {
        if(g==a[i])
        {
            u=i;
        }
    }
    int flag=0;
    if((u/m)%2==0){
        cout<<u/m+1<<" "<<u%n+1;
    }
    else{
        cout<<u/m+1<<" "<<n-(u%n);
    }
    return 0;
}
