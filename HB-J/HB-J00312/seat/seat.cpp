#include<iostream>
#include<algorithm>
using namespace std;
int n,m,a[105],r,x=1,y=1;
void mov(){
    if(y%2){
        if(x==n) y++;
        else x++;
    }
    else{
        if(x==1) y++;
        else x--;
    }
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    r=a[1];
    sort(a+1,a+n*m+1,greater<int>());
    for(int i=1;i<=n*m;i++){
        if(a[i]==r){
            cout<<y<<" "<<x;
            return 0;
        }
        mov();
    }
}