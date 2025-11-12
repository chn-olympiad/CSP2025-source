#include<bits/stdc++.h>
using namespace std;
long long n,m;
int seat_c(int score,int x,int y, int node){
    if(score==node){
        cout<<x<<" "<<y;
        return;
    }
    if(y%2==1 && x<n) return seat_c(score,x,y+1,node+1);
    if(y%2==1 && x==n) return seat_c(score,x+1,y,node+1);
    if(y%2==0 && x<i) return seat_c(score,x-1,y,node+1);
    if(y%2==0 && x==1) return seat_c(score,x,y+1,node+1);
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    seat_c(2,1,1,1);
}
