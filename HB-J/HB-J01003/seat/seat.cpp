#include<bits/stdc++.h>
using namespace std;
int n,m,a[1100];
int l,h;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int all = n*m;
    for(int i=1;i<=all;i++)
    {
        cin>>a[i];
    }
    int p,R = a[1];
    sort(a,a+all+1);
    for(int i=1;i<=all;i++)
    {
        if(a[i]==R) p=all+1-i;
    }
    if(p%n!=0) l=p/n+1;
    else l = p/n;
    int x = p-(l-1)*n;
    if(l%2!=0) h = x;
    else h = n+1-x;
    cout<<l<<" "<<h;
    return 0;
}
