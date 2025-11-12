#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[102],sum=0;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        if(a[i]>a[1]) sum++;
    }
    cout<<sum/n+1<<' ';
    if((sum/n+1)%2==1){
        cout<<sum%n+1;
    }
    else{
        cout<<n-sum%n;
    }
    return 0;
}
