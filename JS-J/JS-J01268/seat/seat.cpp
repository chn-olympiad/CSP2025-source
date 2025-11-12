#include<bits/stdc++.h>
using namespace std;
int n,m,b[101],w,x=1,y=1,h;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    h=n*m;
    for(int i=1;i<=h;i++){
        scanf("%d",&b[i]);
    }
    w=b[1];
    sort(b+1,b+h+1);
    for(int i=h;i>0;i--){
        if(b[i]==w){
            cout<<x<<" "<<y;
            return 0;
        }
        if(x%2==1){
            if(y==n) x++;
            else y++;
        }
        else if(y==1) x++;
        else y--;
    }
    return 0;
}
