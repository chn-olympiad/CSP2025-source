#include<bits/stdc++.h>
using namespace std;
long long a,n,m;
long long p,x=1,y=1;
int main(){
    freopen("seat.out","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        int b;
        cin>>b;
        if(i==0){
            a=b;
        }
        else if(b>a){
            p++;
        }
    }
    int flag=0;
    for(int i=0;i<p;i++){
         if(flag==1){
            y++;
            flag=0;
            continue;
         }
         if(y%2==1){
            x++;
         }
         else{
            x--;
         }
         if(x==1||x==n){
            flag=1;
         }
    }
    cout<<y<<" "<<x;
    return 0;
}
