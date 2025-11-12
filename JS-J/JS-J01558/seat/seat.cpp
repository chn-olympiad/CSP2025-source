#include<bits/stdc++.h>
using namespace std;
int n,m;
int arr[105];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++)
    cin>>arr[i];
    int k=arr[0];
    sort(arr,arr+n*m);
    for(int i=0;i<n*m;i++)
    {
        if(arr[i]==k)
            k=n*m-i;
    }
    int t=k/n+(k%n!=0);
    cout<<t<<' ';
    if(t%2!=0)
    {
        if(k%n==0)
        cout<<n;
        else
        cout<<k%n;
    }
    else
    {
        if(k%n==0)
        cout<<1;
        else if(k%n==1)
        cout<<n;
        else
        cout<<n-k%n+1;
    }
    return 0;
}
