#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a[105];
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=(n*m);i++)cin>>a[i];
    int k=a[1];
    int  ans=0;
    sort(a+1,a+m*n+1);
    for(int i=1;i<=(n*m);i++){
        if(a[i]==k)
        {
            ans=m*n-i+1;
            //cout<<ans<<endl;
        }
    }
    int y=0,x=0;
    if(ans%n==0)x=ans/n;
    else if(ans%n!=0)x=ans/n+1;
    if(x%2==1){
        if(ans%n!=0)y=ans%n;
        if(ans%n==0)y=n;
    }
    if(x%2==0){
        if(ans%n==0)y=1;

        else if(ans%n!=0)y=n+1-ans%n;
    }
    cout<<x<<" "<<y;
    return 0;
}
