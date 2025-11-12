#include<bits/stdc++.h>
using namespace std;
int a[105];
int b[105];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,x,r,c;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>b[i];
    }
    x=b[1];
    sort(b,b+n*m+1);
    for(int i=1;i<=n*m;i++){
        a[n*m-i+1]=b[i];
    }
    for(int i=1;i<=n*m;i++){
        if(a[i]==x){
            x=i;
            break;
        }
    }
    c=(x-1)/n+1;
    if(c%2==0)r=n-(x-(c-1)*n)+1;
    else r=x-(c-1)*n;
    cout<<c<<" "<<r;
    return 0;
}
