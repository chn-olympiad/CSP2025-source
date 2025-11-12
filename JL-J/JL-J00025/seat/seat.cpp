#include <iostream>
#include <queue>
using namespace std;
priority_queue<int,vector<int>,less<int> > q;
int _n,_m;
int a1,x;
int _x=1,_y=1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>_n>>_m;
    for(int i=1;i<=_n*_m;i++){
        cin>>x;
        if(i==1)
            a1=x;
        q.push(x);
    }
    while(!q.empty()){
        int x=q.top();
        q.pop();
        if(x==a1){
            cout<<_y<<' '<<_x<<endl;
            return 0;
        }
        if(_y%2==1){
            if(_x==_n)
                _y++;
            else
                _x++;
        }
        else{
            if(_x==1)
                _y++;
            else
                _x--;
        }
    }
    return 0;
}
