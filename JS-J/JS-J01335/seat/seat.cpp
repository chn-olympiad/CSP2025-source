#include<bits/stdc++.h>
using namespace std;
int a[101];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,k=1;
    cin>>m>>n;
    int s=n*m;
    cin>>a[1];
    for(int i=2;i<=s;i++)
    {
        cin>>a[i];
        if(a[i]>a[1])k++;
    }
    int A=1+(k-1)/n;
    cout<<A<<" ";
    if(A%2==0)
    {
        if(k%n==0)
        {
            cout<<1;
            return 0;
        }
        else
        {
            cout<<n-k%n+1;
            return 0;
        }
    }
    if(A%2==1)
    {
        if(k%n==0)
        {
            cout<<n;
            return 0;
        }
        else
        {
            cout<<k%n;
            return 0;
        }
    }
    return 0;
}
