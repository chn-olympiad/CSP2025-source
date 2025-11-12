#include <bits/stdc++.h>
using namespace std;
int n,m,f,s[100005],c,r;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>s[i];
    }
    f=s[1];
    sort(s+1,s+1+n*m);
    for(int i=1;i<=n*m;i++){
        if(s[i]==f){
            f=n*m-i+1;
            break;
        }
    }
    if(f%n==0){
        c=f/n;
    }else{
        c=f/n+1;
    }
    if(c%2==0){
        r=n-(f-(c-1)*n)+1;
    }else{
        r=f-(c-1)*n;
    }
    cout<<c<<" "<<r;
    return 0;
}
