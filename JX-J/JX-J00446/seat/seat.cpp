#include<bits/stdc++.h>
using namespace std;
int a[105],x,n,m,h,l;
bool cmp(int x,int y){
    return x<y;
}
int main(){
    freopen("seat.in","r","stdin");
    freopen("seat.out","w","stdout");
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    x=a[1];
    for(int i=1;i<=n*m;i++){
        for(int i=1;i<=n*m;i++){
            if(a[i]<a[i+1]){
                int t=a[i];
                a[i]=a[i+1];
                a[i+1]=t;
            }
        }
    }
    for(int i=1;i<=n*m;i++){
        if(a[i]==x) x=i;
    }
    if(x%n==0){
        l=x/n;
        if(l%2==0) h=1;
        else h=n;
    }
    else{
        l=(x/n)+1;
        if(l%2==0)
            if(x%n!=0) h=n-(x%n)+1;
            else h=1;
        else{
            if(x%n==0) h=n;
            else h=x%n;
        }
    }
    cout<<l<<' '<<h;
    return 0;
}
