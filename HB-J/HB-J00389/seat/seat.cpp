#include<bits/stdc++.h>
using namespace std;
int n,m,c,r;
int a[110];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=(n*m);i++)cin>>a[i];
    if(n==1){
        if(m==1){
            c=1;
            r=1;
        }
        if(m>1){
            r=1;
            if(a[1]>a[m])c=1;
            if(a[1]<a[m])c=m;
        }
    }
    if(n==2){
        if(m==2){
            if(a[1]>a[2]){
                if(a[1]>a[3]){
                    if(a[1]>a[4])c=1;r=1;
                    if(a[1]<a[4])c=1;r=2;
                }
                if(a[1]<a[3]){
                    if(a[1]>a[4])c=1;r=2;
                    if(a[1]<a[4])c=2;r=2;
                }
            }
            if(a[1]<a[2]){
                if(a[1]>a[3]){
                    if(a[1]>a[4])c=1;r=2;
                    if(a[1]<a[4])c=2;r=2;
                }
                if(a[1]<a[3]){
                    if(a[1]<a[4])c=2;r=1;
                    if(a[1]>a[4])c=2;r=2;
                }
            }
        }
    }
    if(m==1){
        c=1;
        if(a[1]>a[n])r=1;
        if(a[1]<a[n])r=n;
    }
    cout<<c<<" "<<r;
    return 0;
}
