#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,sum=1,t=0;
    cin>>n>>m;
    cin>>a[1];
    for(int i=2;i<=n*m;i++){
        cin>>a[i];
        if(a[i]>a[1]){
            sum++;
        }
    }
    if(sum%n==0){
        t=sum/n;
    }
    else{
        t=sum/n+1;
    }
    if(t%2!=0){
        if(sum%n==0){
            cout<<t<<' '<<n;
        }
        else{
            cout<<t<<' '<<sum%n;
        }
    }
    else{
        if(sum%n==0){
            cout<<t<<' '<<1;
        }
        else{
            cout<<t<<' '<<n+1-sum%n;
        }
    }
    return 0;
}
