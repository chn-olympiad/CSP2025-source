#include<bits/stdc++.h>
using namespace std;
int n,m,x,c,r;
int a[1005];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    x=a[1];
    sort(a+1,a+n*m+1);
    int s;
    for(int i=n*m;i>=1;i--){
        if(a[i]==x){
            s=n*m-i+1;
        }
    }
    c=1;
    int d=s;
    while(d>n){
        c++;
        d=d-n;
    }
    if(c%2==0){
        r=n-(s-(c-1)*n)+1;
    }else{
        r=s-(c-1)*n;
    }
    cout<<c<<" "<<r;
    return 0;
}
