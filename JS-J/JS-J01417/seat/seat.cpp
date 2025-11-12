#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a,s;
    int y,t;
    cin>>a>>s;
    int z;
    int u[100];
    for(int i=0;i<a*s;i++){

        cin>>z;
        if(i==0)y=z;
        u[i]=z;
    }
    sort(u,u+a*s);
    for(int i=0;i<a*s;i++){
        if(u[i]==y){
            y=a*s-i;
        }
    }
    cout<<(y-1)/a+1<<' ';
    if(((y-1)/a)%2==0){
        cout<<y-(((y-1)/a)*a);
    }
    else{
        cout<<a-(y-a*(y-1)/a)+1;
    }

    return 0;
}
