#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main(
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n,c,r;
    cin>>m>>n;
    int b=m*n;
    int p;
    for(int i=0;i<b;i++){
        p=a[0];
        cin>>a[i];
    }
    sort(a,a+b);
    int q;
    for(int i=0;i<b;i++){
        if(p==a[i]){
            q=i;
            break;
        }
    }
    if(q/n<1){
        c=1;
        r=q;
        cout<<c<<" "<<r;
    }else if(q%n=0){
       if((q/n)%2==0){
           c=q/n;
           r=1;
       }else{
           c=q/n;
           r=n;
       }
        cout<<c<<" "<<r;
    }else{
        if((q/n)%2==0){
            c=(q/n)+1;
            r=n-(q%n);
        }else{
            c=(q/n)+1;
            r=q%n;
        }
        cout<<c<<" "<<r;
    }
    return 0;
)