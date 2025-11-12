#include<bits/stdc++.h>
using namespace std;
int m,n,c,r,a[105],pai;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m*n;i++){
        cin>>a[i];
    }
    int p=a[1];
    int q=n*m;
    for(int i=1;i<=q;i++){
        for(int i=1;i<=q;i++){
            if(a[i]<a[i+1]){
                swap(a[i],a[i+1]);
            }
        }
    }
    for(int i=1;i<=n*m;i++){
        if(p==a[i]){
            pai=i;

        }
    }
    int a=pai/n,b=pai%n;
    if(b==0){
        if(a%2==0){
            c=a;
            r=1;
        }else{
            c=a;
            r=n;
        }
    }else{
        c=a+1;
        if(a%2==0){
            r=b;
        }else{
            r=n-b+1;
        }


    }
    cout<<c<<" "<<r;
return 0;
}
