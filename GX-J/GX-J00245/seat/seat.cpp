#include<bits/stdc++.h>
using namespace std;
int n,m,x=1,y=1;
void f(int b){
    if(b==1){
        cout<<x<<" "<<y<<endl;
        return;
    }
    if(x%2){
        if(y<n){
            y+=1;
        }
        else{
            x+=1;
        }
    }
    else{
        if(y>1){
            y-=1;
        }
        else{
            x+=1;
        }
    }
    f(b-1);
    return;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int i,b,c;
    cin>>n>>m;
    int a[n*m+1];
    for(i=1;i<=n*m;i+=1){
        cin>>a[i];
    }
    b=a[1];
    sort(a+1,a+n*m+1);
    for(i=1;i<=n*m;i+=1){
        if(a[i]==b)
        c=n*m-i+1;
    }
    f(c);
    return 0;
}
