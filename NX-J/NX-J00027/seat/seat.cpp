#include<bits/stdc++.h>
using namespace std;
int a[1000],hx=0;
int n,m;
bool f = 1;
int x=1,y=1;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
cin >>n>>m;
int z = n*m;
for(int i = 1;i<=z;i++){
    cin>>a[i];
}
for(int i = 2;i<=z;i++){
    if(a[i]>a[1] && f == 1){
        if(hx == 1){
            hx = 0;
            x++;
        }else y++;
        if(y == n){
            f = 0;
            hx = 1;
        }
    }else if(a[i]>a[1] && f == 0){
        if(hx == 1){
            hx = 0;
            x++;
        }else y--;
        if(y == 1){
            f = 1;
            hx = 1;
        }
    }
}cout<<x<<" "<<y;
fclose(stdin);
fclose(stdout);
return 0;
}
