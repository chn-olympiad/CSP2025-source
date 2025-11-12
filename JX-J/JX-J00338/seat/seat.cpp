#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in",'r',stdin);
    freopen("seat.out",'w',stdout);
    int n,m;
    int a[121];
    int c,r;
    cin>>n>>m;
    int p=m*n;
    for(int i=0;i<=p-1;i++){
        cin>>a[i];
    }
    int x=a[0];
    for(int i=0;i<=p-1;i++){
        for(int j=0;j<=p-i-1;j++){
            if(a[j]<a[j+1]) swap(a[j],a[j+1]);
        }
    }
    int l;
    for(int i=1;i<=p;i++){
        if(a[i]==x){
            l=i;
        }
    }
    int h=l;
    if(l%n==0) l-=1;
    int g=floor(l/n+1);
    c=g;
    if(g%2!=0){
            r=h-(c-1)*n;
    }
    if(g%2==0){
            r=n+1-h+(c-1)*n;
    }
    cout<<c<<" "<<r;
    return 0;
}
