#include<bits/stdc++.h>
using namespace std;
int arr[100+14];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int ms;
    for(int i=1;i<=n*m;i++)
    {
        cin>>arr[i];
    }
    ms=arr[1];
    sort(arr+1,arr+n*m+1,greater<int>());
    int p;
    for(int i=1;i<=n*m;i++)
    {
        if(arr[i]==ms)
        {
            p=i;
            break;
        }
    }
    int x=p/n+bool(p%n);
    int y;
    if(x%2)
    {
        y=((p-1)%n)+1;
    }
    else
    {
        y=n-((p-1)%n);
    }
    cout<<x<<' '<<y;
    return 0;
}
