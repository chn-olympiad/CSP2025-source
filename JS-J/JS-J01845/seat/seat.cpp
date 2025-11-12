#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],me,mes;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    me=a[1];
    sort(a,a+n*m+1);
    for(int i=n*m;i>=1;i--){
        if(a[i]==me){
            mes=n*m-i;
        }
    }
    int h,l=mes/n+1;
    if(l%2==0){
        h=n-(mes%n);
    }
    else{
       h=mes%n+1;
    }
    cout<<l<<' '<<h;
return 0;
}
