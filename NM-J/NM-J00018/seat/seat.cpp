#include<bits/stdc++.h>
using namespace std;
int n,m,p,f,c,r;
int a[200];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    p=a[1];
    sort(a+1,a+n*m+1,greater<int>());
    for(int i=1;i<=n*m;i++) {
        if(a[i]==p) {f=i;break;}
    }
    c=f/n;
    if(c*n<f) c++;
    if(c%2==1){
        r=(f%n);
        if((f%n)==0) r=n;
    }else{
        r=n-(f%n)+1;
        if((f%n)==0) r=1;
    }
    cout<<c<<" "<<r;
    return 0;
}