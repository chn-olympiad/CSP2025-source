#include<bits/stdc++.h>
using namespace std;
int c,R,n,m,r,s,tmp,a[1000];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;cin>>R;s++;
    for(int i=2;i<=n*m;i++){
        cin>>tmp;
        if(tmp>R){
            s++;
        }

    }
    c=s/n+1;
    if(c%2==1){
        r=s%n;
    }else{
        r=n-s%n+1;
    }
cout<<c<<' '<<r;
return 0;
}


