#include<bits/stdc++.h>
using namespace std;
int a[103];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,cnt=1,x,y;
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    for(int i=1;i<n*m;i++){
        if(a[0]<a[i]){
            cnt++;
        }
    }
    x=(cnt-1)/n+1;
    if(x%2==1){
        y=cnt%n;
        if(y==0){
            y=n;
        }
    }
    else{
        y=n-cnt%n+1;
    }
    cout<<x<<' '<<y;
    return 0;
}
