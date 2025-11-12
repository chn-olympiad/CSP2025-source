#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a,b,c=0,x,y;
    cin>>x>>y;
    for(int i=1;i<=x;i++){
        for(int j=1;j<=y;j++){
            cin>>a;
            if(i==1 and j==1){
                b=a;
            }
            if(b<a){
                c++;
            }
        }
    }
    for(int i=1;i<=y;i++){
            if(i%2==1){
        for(int j=1;j<=x;j++){
            if(c==0){
                cout<<y<<" "<<x;
                return 0;
            }
            c--;
        }
                if(i%2==0){
        for(int j=x;j>=1;j--){
            if(c==0){
                cout<<y<<" "<<x;
                return 0;
            }
            c--;
        }
            }
    }
}
    }
