#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int x,y,z,sum,num=1;
    cin>>x>>y>>z;
    for(int i=2;i<=x*y;i++){
        cin>>sum;
        if(sum>z){
            num++;
        }
    }
    int q=floor((num-1)/x)+1;
    cout<<q<<" ";
    if(q%2==1){
        if(num%x==0){
            cout<<x;
        }else{
            cout<<num%x;
        }
    }else{
        if(num%x==0){
            cout<<1;
        }else{
            cout<<x-num%x+1;
        }
    }
}
