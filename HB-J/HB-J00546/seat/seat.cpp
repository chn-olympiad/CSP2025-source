#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,c,r,x,y;
    int a[105];
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        x=a[1];
    }
    sort(a+1,a+n*m+1);
    for(int i=1;i<=n*m;i++){
        if(a[i]==x){
            y=n*m-i+1;
    }
}
    if(y%n==0){
        c=y/n;
    }else{
        c=y/n+1;
    }
    if(c%2==0){
        r=n-y%n+1;
    }else{
        r=y-(c-1)*n;
    }
    cout<<c<<' '<<r;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
