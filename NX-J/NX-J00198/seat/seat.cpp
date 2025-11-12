#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[105],c=0,r,s;
    cin>>n>>m;
    cin>>a[0];
    for(int i=1;i<n*m;i++){
        cin>>a[i];
        if(a[i]>a[c])c=i;
    }
    r=c/n+1;
    if(r%2==1)s=c%n+1;
    else s=m-c%n;
    cout<<r<<' '<<s;
    return 0;
}
