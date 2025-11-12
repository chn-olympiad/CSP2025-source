#include<bits/stdc++.h>
using namespace std;
int rs,n,m,x,arr[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
       cin>>arr[i];
    }
    rs=arr[1];
    sort(arr+1,arr+n*m+1);
    int pos=n*m-(lower_bound(arr+1,arr+n*m+1,rs)-arr)+1;
    //cout<<pos<<'\n';
    int lie=ceil(pos*1.0/n),rk=pos%n;
    if(lie%2==1){
        cout<<lie<<" ";
        if(rk==0)cout<<n;
        else cout<<rk;
    }
    else{
        cout<<lie<<" ";
        if(rk==0)cout<<1;
        else cout<<n-rk+1;
    }
    return 0;
}
