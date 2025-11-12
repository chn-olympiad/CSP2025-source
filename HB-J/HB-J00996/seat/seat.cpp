#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
int n,m,nm,a[101],r,tot;
bool up=true;
void snake(int x,int y){
    if(x>n){
        up=false;
        snake(x-1,y+1);
        return;
    }
    if(x<1){
        up=true;
        snake(x+1,y+1);
        return;
    }
    if(y>m){
        return;
    }
    if(a[tot]==r){
        cout<<y<<" "<<x<<endl;
        return;
    }
    tot--;
    if(up){
        snake(x+1,y);
    }
    else{
        snake(x-1,y);
    }
    return;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    nm=n*m;
    tot=nm;
    for(int i=1;i<=nm;i++){
        cin>>a[i];
    }
    r=a[1];
    sort(a+1,a+nm+1);
    snake(1,1);
    return 0;
}
