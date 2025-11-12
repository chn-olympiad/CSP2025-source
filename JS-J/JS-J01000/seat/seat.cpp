#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int R=a[1],rnk;
    sort(a+1,a+n*m+1);
    for(int i=1;i<=n*m;i++){
        if(R==a[i]){
            rnk=n*m-i+1;break;
        }
    }
    int x,y=(rnk+n-1)/n;
    if(y&1) x=(rnk-1)%n+1;
    else x=n-(rnk-1)%n;
    cout<<y<<' '<<x;
    return 0;
}
