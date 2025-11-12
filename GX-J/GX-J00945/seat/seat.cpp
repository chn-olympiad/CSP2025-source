#include<bits/stdc++.h>
using namespace std;
int arr[109]={0};
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>arr[i];
    int xy=arr[1];
    int c=0;
    sort(arr+1,arr+n*m+1,cmp);
    for(int i=1;i<=n*m;i++)
        if(arr[i]==xy)
            c=i;
    int x=c/n,y=0;
    if(c%n!=0)
        x++;
    if(x%2==0)
        y=c%n+1;
    else
        if(c%n==0)
            y=n;
        else
            y=c%n;
    cout<<x<<' '<<y;
    return 0;
}
