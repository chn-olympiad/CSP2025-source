#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],R;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>R;
    a[1]=R;
    for (int i=2;i<=n*m;i++){
        cin>>a[i];
    }
    sort(a+1,a+m*n+1);
    int l=0,r=m*n+1;
    while(l<=r){
        int mid=(l+r)/2;
        if (a[mid]>=R)r=mid-1;
        else l=mid+1;
    }
    l=n*m-l+1;
    if (l%n==0){
        if ((l/n)%2==1)cout<<l/n<<" "<<n;
        else cout<<l/n<<" "<<1;
    }
    else{
        if ((l/n+1)%2==0)cout<<l/n+1<<" "<<n-l%n+1;
        else cout<<l/n+1<<" "<<l%n;
    }
}
