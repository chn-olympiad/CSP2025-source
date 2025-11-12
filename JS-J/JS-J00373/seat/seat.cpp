#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[101],r,rn,x,y;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>r;
    a[0]=r;
    for(int i=1;i<n*m;i++){
        cin>>a[i];
    }
    sort(a,a+n*m);
    for(int i=0;i<n*m;i++){
        if(a[i]==r){
            rn=n*m-i;
            break;
        }
    }
    x=(rn-1)/n+1;
    if(x%2==0){
        y=n-((rn-1)%n);
    }else{
        y=(rn-1)%n+1;
    }
    cout<<x<<" "<<y;
    return 0;
}
