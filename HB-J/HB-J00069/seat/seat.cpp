#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long n,m,a[1005],x,y=1;
    cin>>n>>m;
    for(int i = 0;i <= n*m-1;i++){
            cin>>a[i];
    }
    x = a[0];
    for(int i = 1;i <= n*m;i++){
            if(a[i] > x){
                y++;
            }
    }
    if(y % m != 0){
        if((y+1) % m == 0){
            if(y % m == 0 && ceil(y / m) == 1){
                x = floor(y / m);
                y = m;
            }
            else{
                x = floor(y / m)+1;
                y = m;
            }
        }
        else{
            if(y % m == 0 && ceil(y / m) == 1){
                x = floor(y / m);
            }
            else{
                x = floor(y / m)+1;
            }
            if(x % 2 == 0){
                y = y % m + 1;
            }
            else{
                y = m - y % m - 1;
            }
        }
    }
    else{
        x = floor(y / m);
        if(x % 2 == 0){
            y = 1;
        }
        else{
            y = m;
        }
    }
    cout<<x<<" "<<y;
    return 0;
}
