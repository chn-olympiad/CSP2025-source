#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,r,a[100924],seat;
    cin>>n>>m;
    cin>>r;
    a[1]=r;
    for(int i=2;i<=n*m;i++)
        cin>>a[i];
    sort(a+1,a+n*m+1);
    /*for(int i=n*m;i>=1;i--)
        cout<<a[i];*/
    for(int i=n*m;i>=1;i--)
        if(a[i]==r)seat=n*m-i+1;
    int x=(seat-1)/n+1,y;
    if(x%2==1)
         y=(seat-1)%n+1;
    else
         y=n-(seat%n)+1;
    cout<<x<<" "<<y;
}
