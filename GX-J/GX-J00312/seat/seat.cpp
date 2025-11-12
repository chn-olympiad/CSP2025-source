#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,sx,sy,s,n1,x = 1;
    cin>>n>>m;
    cin>>s;
    for(int i = 1;i<n*m;i++){
        cin>>n1;
        if(n1>s){
            x++;
        }
    }
    sx = (x-1)/n+1;
    sy = (x-1)%n+1;
    if(sx%2 == 0){
        sy = n-sy+1;
    }
    cout<<sx<<' '<<sy<<endl;
    return 0;
}
