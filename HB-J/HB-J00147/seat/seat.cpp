
#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int n,m,a[10000],s=0,h,l,c=0;
cin >> n >> m;
for(int i=1;i<=n*m;i++){
    cin >> a[i];
}
s=a[1];
sort(a+1,a+n*m+1);
//s=a[1];
for(int i=n*m;i>=1;i--){
    c =n*m-i+1;
    if(a[i]==s){
    if(c%n==0){
        l=c/n;
    }
    else{
            l=(c-c%n)/n+1;
    }
        //cout << l;
    }

}
for(int i=n*m;i>=1;i--){
    c =n*m-i+1;
    if(a[i]==s){
    if(l%2==1){
        h=c%n;
        if(c%n==0){
            h= n;
        }
    //cout << h;
    }
else{
    h=n-c%n+1;
    if(c%n==0){
        h=1;
    }
}
    }
}
cout << l << " " << h;
return 0;
}
