#include<bits/stdc++.h>
using namespace std;
int n,m,x,sum,ans;
int a[105];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>a[i];
    int re=a[1];
    sort(a+1,a+n*m+1);
    for(int i=1;i<=n*m;i++){
        if(a[i]==re){
            x=n*m-i+1;
            break;
        }
    }
    if(x%m==0){
        sum=x/m;
        if(sum%2==0) ans=1;
        else ans=n;
    }
    else{
        sum=x/m+1;
        if(sum%2==0)
            ans=(m+1)-(x-(sum-1)*m);
        else
            ans=x-(sum-1)*m;
    }
    cout<<sum<<" "<<ans;
    return 0;
}
