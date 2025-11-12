#include <bits/stdc++.h>
using namespace std;
int a[300];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,w;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int q=a[1];
    sort(a+1,a+n*m+1);
     w=lower_bound(a+1,a+n*m+1,q)-a-1;
    w=n*m-w;
    int x,y;
    if(w%n!=0){
       x=w/n+1;
       y=w%n;
    }else{
        x=w/n;
        y=n;
    }
    if(x%2==0){
        y=n-y+1;
    }
    cout<<x<<" "<<y;
    return 0;
}
