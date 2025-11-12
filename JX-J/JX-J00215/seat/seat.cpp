//100pts
#include<bits/stdc++.h>
using namespace std;
int n,m,bj;
priority_queue<int>pq;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    bool f=1;
    for(int i=1;i<=n*m;i++){
        int a;
        cin>>a;
        if(i==1)bj=a;
        pq.push(a);
    }
    int x=1,y=0;
    while(!pq.empty()){
        int a=pq.top();
        pq.pop();
        if(x%2){
            y++;
            if(y>n){
                x++;
                y--;
            }
        }else{
            y--;
            if(y<1){
                x++;
                y++;
            }
        }
        if(a==bj){
            cout<<x<<' '<<y;
            break;
        }
    }
    return 0;
}