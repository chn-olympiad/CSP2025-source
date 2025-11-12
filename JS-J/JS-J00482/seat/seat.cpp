#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int x,y;cin>>x>>y;int a[x*y+1];
    for(int i=1;i<=x*y;i++){
        cin>>a[i];
    };int j=a[1];sort(a+1,a+x*y+1);
    for(int i=x*y;i>=1;i--){
        if(a[i]==j)j=x*y-i+1;
    };int yy,xx;if(j%x==0){
        yy=j/x;
        if(yy%2==0)xx=1;
        else xx=x;}
    else{yy=j/y+1;
    if(yy%2==0)xx=x-(j%yy)+1;
    else xx=j%yy;}
    cout<<yy<<' '<<xx;
    return 0;
}
