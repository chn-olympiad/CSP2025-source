#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[105],k,x,y,c;
    cin>>n>>m>>k;
    a[1]=k;
    for(int i=2;i<=n*m;i++){
        cin>>a[i];
    }
    sort(a,a+n*m+1);
    //for(int i=1;i<=m*n;i++) cout<<a[i]<<" ";
    for(int i=m*n;i>0;i--){
        if(a[i]==k){
            c=m*n+1-i;
            break;
        }
    }
    int cn=c/n;
    if(cn%2==0||cn==0){
        x=c%n;
    }else{
        x=n-c%n;
    }
    y=cn+1;
    cout<<y<<" "<<x;
    return 0;
}
